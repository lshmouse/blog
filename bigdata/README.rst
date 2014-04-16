大数据系统从google的三篇经典论文(GFS, MapReduce, BigTable)开始，
还有Google强大的集群管理系统Borg, 到开源的Hadoop实现(HDFS, Mapreduce,
HBase, Yarn), 慢慢衍生出一个完整平台和生态系统.

Google的道路
------------

-  GFS -> Colossus(GFS2)
-  MapReduce -> Tenzing -> Dremel
-  BigTable -> Procator -> MegaStore -> Spanner
-  Borg -> Omega

Hadoop的道路
------------

开源Hadoop基本上跟着Google的路走, 只不过慢了N年. 不过这也是需求驱动，
毕竟没有几个公司到达Google那个规模。

-  核心：HDFS. Mapreduce, HBase, Yarn
-  外围: Hive, Storm
-  黑马: Spark

Amazon的道路
------------

Amazon是一个比较独立技术道路，主要AWS形式对外提供云服务。

EC2, EBS, S3, DynamoDB

大规模运维和监控系统
--------------------

这是各个大公司软实力所在，这些基础的系统好坏直接关系到服务质量和产品迭代速度。

在这里记录一些对这些技术的理解, 欢迎交流～ lshmouse@gmail.com
