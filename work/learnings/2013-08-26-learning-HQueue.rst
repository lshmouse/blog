今天前在weibo上看见一淘在hbase基础上实现了分布式的消息队列：HQueue,
和kafka对比研究了一些。

HQueue参考:基于Hadoop\_HBase的一淘搜索离线系统
http://wenku.baidu.com/view/67d70e5dbe1e650e52ea99f7.html#39124-tsina-1-75084-7f31e6706fc679e86eccddbc982dcff7
kafka参考: http://data.linkedin.com/opensource/kafka

基本概念
~~~~~~~~

paritition：

Topic:

顺序保证
~~~~~~~~

kafaka保证在一个paritition内部是保序的

数据持久性:
~~~~~~~~~~~

HQueue存储在hbase上，hbase将持久化在hdfs上,数据三备份，可以保证数据的高可用性。

kafka将数据存储在本地磁盘上，如果broker机器上磁盘出现问题，就会导致数据丢失.

高可用性
~~~~~~~~

