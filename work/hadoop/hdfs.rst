HDFS
======

Pipeline
----------------------

创建
~~~~~~~
Pipeline与Block一一对应的.

Pipeline写数据和ACK确认是线程分离的，可以支持多个写数据流程并发执行。

客户端(DFSOutputStream) 负责发送的DataStreamer, 负责接受ACK是ResponseProcessor.
DataNode(DataXceiver)上负责数据接受/向下发送数据的是BlockReceiver, 负责接受和发送ACK的是PacketResponder

写数据流程: client -> DataNode0 -> DataNode1 -> DataNode2
ACK确认流程: client -> DataNode0 -> DataNode1 -> DataNode2

PipeLine异常恢复
~~~~~~~~~~~~~~~~~~~
当客户端收到DataNode Ack异常的时候，客户端会尝试重建pipeline
- 根据Ack里面每个datanode返回信息，确认是pipeline上那个datanode上异常，并从pipeline剔除这个datanode
- 重新想Namenode申请datanode, 作为pipeline上最后一个节点
- 向pipeline上第一个datanode发起TRANSFER_BLOCK命令， 将已经写入的block 复制到pipeline上新加的节点
- DataNode收到TRANSFER_BLOCK命令之后，读取本地Block数据，发送到新加节点上，复制成功之后返回客户端
- 客户端收到TRANSFER_BLOCK成功之后，重新建立pipeline

pipeline恢复的核心是TRANSFER_BLOCK, 一般一个block的大小为64M，
最坏情况下，复制一个64M的block从一个datanode到另外一个Datanode时间： max(64M / 网络带宽, 64M / 磁盘速率),
理想状态下这个时间1s左右. 这对于离线业务来说可以接受，导致实时的在线业务来说，可能不是最优化的方案。

DataNode
------------------
DataNode数据本地存储
~~~~~~~~~~~~~~~~~~~~
FsDatasetSpi对应DataNode对底层存储的抽象，具体实现参见FsDatasetImpl。
FsVolumeSpi对应Datanode上一个独立磁盘或者卷的抽象，具体实现参见FsVolumeImpl
一个FsDatasetImpl管理多个FsVolumeImpl, 一个FsVolumeImpl包含很多个具体的Blocks,
Block在磁盘的分配是通过RoundRobin来分配到具体卷上的(这是一个可以改进的地方)

Block 到 Volume的映射维护在一个内存结构ReplicaMap中

参考
-----
- http://yanbohappy.sinaapp.com/?p=143
