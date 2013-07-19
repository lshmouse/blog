Hbase issues
============================

Too many Hlogs
------------------------
Reason: diff regions with diff loads. And the region with little load will
block the delete of hlogs.

Solution: (1) A backend thread to cleanup the entries in the hlogs which had 
been flushed to fileSytem.


Hbase Compaction
-----------------------
Tier based compaction: https://issues.apache.org/jira/browse/HBASE-6371
upport level compaction: https://issues.apache.org/jira/browse/HBASE-7519
Support stripe compaction: https://issues.apache.org/jira/browse/HBASE-7667


Hlog split
---------------------------
https://issues.apache.org/jira/browse/HBASE-7006

cloudera blog
----------------------------
http://blog.cloudera.com/blog/2012/06/hbase-write-path/
http://blog.cloudera.com/blog/2013/04/how-scaling-really-works-in-apache-hbase/
http://blog.cloudera.com/blog/2013/01/apache-hbase-internals-locking-and-multiversion-concurrency-control/

http://blog.cloudera.com/blog/2012/07/hbase-log-splitting/
http://blog.cloudera.com/blog/2012/06/online-hbase-backups-with-copytable-2/

http://blog.cloudera.com/blog/2012/01/caching-in-hbase-slabcache/
http://blog.cloudera.com/blog/2011/02/avoiding-full-gcs-in-hbase-with-memstore-local-allocation-buffers-part-1/

http://blog.cloudera.com/blog/2012/06/hbase-io-hfile-input-output/

http://blog.cloudera.com/blog/2012/07/hbase-replication-overview-2/
http://blog.cloudera.com/blog/2012/08/hbase-replication-operational-overview/

http://blog.cloudera.com/blog/2012/11/apache-hbase-assignmentmanager-improvements/
=======
Namespace
---------------------------
https://issues.apache.org/jira/browse/HBASE-8015
