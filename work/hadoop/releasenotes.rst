Hadoop Release Notes
====================

hadoop-2-0-3
------------

see:
http://blog.cloudera.com/blog/2013/02/apache-hadoop-2-0-3-alpha-released/

比较感兴趣的issue： (a) HDFS-3077: Quorum-based NameNode HA.
不再需要特殊的硬件如NFS,
实现namenode的高可用性，设计和实现文档都非常详细：https://issues.apache.org/jira/secure/attachment/12547598/qjournal-design.pdf
是cloudera贡献的。

(b) yarn的日渐成熟。现在yarn的RM(reource
    manager)还是一个单点故障。不过yarn支持RM的recovery(https://issues.apache.org/jira/browse/YARN-128);
    资源调度增加对cpu的考虑，支持cgroup的container，做到task之间更好的隔离(cpu/memmory,
    磁盘io和网络隔离感觉还不完善)。yarn已经越来越成熟，在yahoo内部，在yarn上已经运行了上千万个job

