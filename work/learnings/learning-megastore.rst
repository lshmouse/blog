MegaStore
=============
今天组内大神分享了google MegaStore的设计,
先把自己理解了部分记录下来，以后在对照论文，加深理解.

MegaStore是google构建在bigtable之上跨数据中心，支持事务，支持sql的分布式数据库方案

基本架构
~~~~~~~~

MegaStore library: MegaStore客户端库，方便用户使用megaStore Replication
Manager: 与一个数据中心的BigTable对应，负责管理 Coordinator:
负责本replica那些entry groups是最新。

在Current Read时，对于当前写的Entry Group, 当前的Replica是最新的， Current
Read就可以直接本地读。 如果不是最新的Current
Read时候，需要Apply没有完成的事务日志，使得当前当前Replica达到最新。

BigTable: 存储实际表的数据和事务日志

数据模型
~~~~~~~~

写流程
~~~~~~

(1) 发起一个Current Read, 获取当前操作日志的postion/timestamp
(2) 发起一次paxos的写操作，将当前的操作日志写到BigTable上Enntry
    Group的Root Row的操作日志列上
(3) 对于未正常返回的
(4) 异步将当前操作写到bigtable的数据行上。

读流程
~~~~~~

性能
~~~~

单个Entry Group, 读写10ms， 写100-400ms， 取决于跨机房的延时。
虽然单个Entry Group的写性能比较差，但是一个表可以分为非常多的Entry
Group，如互联网业务中一个用户一个entry group。总的吞吐量是比较大。
