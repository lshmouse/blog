HDFS 实现要点
======================

客户端
-----------------
DFSClient
~~~~~~~~~~
- NameNode交互
- 文件租约管理

DFSInputStream
~~~~~~~~~~~~~~
BlockReaderLocalLegacy
RemoteBlockReader

接受读Packet PacketReceiver

DFSOutputStream
~~~~~~~~~~~~~~~~
发送Packet DataStreamer
接受Ack ResponseProcessor

DataNode
-----------------

DataXceiver
~~~~~~~~~~~

NameNode
-----------------


协议
----------------

Client <--> NameNode
~~~~~~~~~~~~~~~~~~~~~~~
ClientProtocol
- create/Close/rename/move ...
- leaserecovery
- blocklocation

Client <--> DataNode 
~~~~~~~~~~~~~~~~~~~~~~~
DataTransferProtocol
- Read
- Write

DataNode <--> NameNode
~~~~~~~~~~~~~~~~~~~~~~~~
DatanodeProtocol
- Register
- block report

分布式NameNode探索
~~~~~~~~~~~-----------
- http://code.google.com/a/apache-extras.org/p/giraffa/
- http://www.slideshare.net/schubertzhang/rockstor-a-cloud-object-system-based-on-hadoop
- http://www.bitstech.net/2013/12/16/hadoop-object-storage/

参考
------------------
- http://www.slideshare.net/hanborq/hadoop-hdfs-detailed-introduction
- http://www.slideshare.net/KonstantinVShvachko/hdfs-design-principles
- http://www.slideshare.net/acordova00/design-for-a-distributed-name-node
- http://yanbohappy.sinaapp.com
