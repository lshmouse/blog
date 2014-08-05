实时存储系统设计文档
===================================

设计目标
--------------
- 可扩展性(支持5k个节点)
- 低延时/高可用性
- 支持强一致性
- 强类型（基本数据类型 + pb /thrift）
- 支持访问/权限控制
- 支持多数据中心
- 支持多租户隔离(SLA)
- 支持不同类型存储引擎(LSM tree/B+ tree/内存)
- 可选择的一致性(可选)

数据模型
----------------
类似Google BigTable 
NameSpace -> Table -> EntryGroup -> Row -> LocalityGroup -> Column -> timestamp 

用户接口
----------------
原生API
~~~~~~~~~~~~~~~~~~
基本的Put/Get/Delete/ConditionMutate

类SQL
~~~~~~~~~~~~~~~~~~
只支持优先集合的SQl(不支持join等)

整体架构
----------------
Master-Slave架构
多个Master构成一个replica group, Master内部为一个状态机，负责整个集群的控制流，以及服务Meta表。

Table按照range/hash 划分为不同region,
每个region有多个replica， 分布在不同数据中心和机架.
这个有表创建时候指定（默认是本数据中心两个备份，异地数据中心一个备份）
这些replica构成一个replica group， 使用raft协议保持同步。
一个replica down机，使用paxos 协议选主重新服务

每个Region大小为1-10G, 过大的Region可能导致节点down机恢复时候并行度较低，恢复时间较长。

实现
----------------
golang + protobuf + raft

golang好处
~~~~~~~~~~~~~~~~
- 语言支持rpc, cpu/memoey profile
- 基本库: raft/sstable

golang可能的问题
~~~~~~~~~~~
- Golang的GC问题
- 新的语言的熟悉和掌控程度

多租户
~~~~~~~~~~~~~~~
Namespace quota
Data Amount quota
Request quota

参考
---------------
- weed-fs https://code.google.com/p/weed-fs/
- HydraBase https://code.facebook.com/posts/321111638043166/hydrabase-the-evolution-of-hbase-facebook/
- cockroach https://github.com/cockroachdb/cockroach
- rocksdb http://rocksdb.org/ 
