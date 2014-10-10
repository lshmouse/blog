HFile和HLog的回收机制
===========================
正常回收流程
------------
HBase数据主要存储在分布式文件系统上HFile和HLog文件中。
HBase数据基于LSM模型，写操作写到内存(MemStore)和Write Ahead Log(HLog)就返回。
当内存不足或者MemStore超过一定大小的时候，HBase会将MemStore的数据顺序写到分布式文件系统上，形成一个HFile。
当小的HFile过多的时候，会将多个小的HFile压缩形成一个大的HFile。
压缩完成之后这些小的HFile就被移动archive目录下。

如果HLog里所有记录对应的数据都已经刷新到HFile上，HLog就被RegionServer移动到.oldlog目录下。
HMaster上的定时线程HFileCleaner/LogCleaner周期性扫描archive目录和.oldlog目录, 判断目录下的HFile或者HLog是否可以被删除，
如果可以就直接删除文件。

TimeToLive
---------------
为了防止系统错误删除HFile/HLog, HFile/HLog都有一个全局的过期时间（TTL）, 超过这个过期时间的HFile/HLog才被删除.

Replication
---------------
HBase的Replication是通过将主集群的HLog推送到备集群，然后在备集群上重放实现的, 因此如果在oldlog目录下的HLog还在被Replication使用中，这些文件不能删除。
HMaster上的ReplicationLogCleaner负责跟踪Replication正在使用那些HLog，如果检测到所有Replication都没有使用或者使用完了这个HLog文件，HLog文件就可以删除了。

SnapShot
-------------
Table的Snapshot只创建了一些HFile的引用，SnapshotFileCache负责跟踪那些HFile现在被某个Snapshot引用，
HMaster上的HFileCleaner在尝试删除HFile时候会通过SnapshotHFileCleaner检查HFile是否被引用，如果被引用就不能删除。

Region Split
--------------
当Region大小超过一定阈值时，Region会自动分裂成两个子Region. Region Split执行时间是秒级别的. 
Split前父Region会预flush一次,然后关闭Region的写，最后做一次flush, 保证Region所有的数据都写到HFile中。
Split时两个Region并不实际分割父Region的HFile，而是在子Region目录下生成一个HFile引用, 指向父Region实际的HFile文件，
等到时候子Region Compaction时候才生产真实的HFile.
父Region的HFile文件何时删除呢？HMaster上定时线程CatalogJanitor会周期性检查Meta表上的Region，是否是分裂后的父Region，
并检查子Region是否还有到父Region的引用。直到子Region中所有引用HFile都被compaction回收之后，父Region的HFile就可以被回收，
被移动到archive目录下。
