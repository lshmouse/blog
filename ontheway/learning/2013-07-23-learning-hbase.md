---
layout: post
title: 'learning hbase'
tags: [hbase]
categories:
- learning
---
{% include JB/setup %}

hbase是一个面向列的，分布式，强一致性NoSQL数据库。hbase是google
bigtable的开源实现。
###数据模型

![hbase data model]({{BASE_PATH}}/assets/img/hbase-data-model.png)

- table: hbase里，一类记录的集合称为一个table。一个表包含很多row.
- row key: 一行数据的主key，用于访问hbase查询。hbase保证同一行的原子性。需要根据业务的访问模式，来优化和设计rowkey.
- column familiy: 一组经常一起访问的column的集合的名字，同一个column family的数据在物理上存储在同一组hfile里面
- column: 一行包含一个row key + 很多列。在表创建时，不需要指定column的名字，只需要指定column family的名字。也就是说一个column family可以包含很多列，并且可以动态添加。
- timestamp/version: 数据的版本，或者时间戳，用于存储数据的版本。
- data: 实际数据，为byte流。一般需要在client端将基本类型(bool, int, long, double等)，或者thrift,protobuf对象序列化为字节流，然后存储在hbase里

####物理存储结构

面向列的存储

###架构

![hbase architecture]({{BASE_PATH}}/assets/img/hbase-arch.png)

####水平扩展
hbase table所有数据是按照row key有序的。通过range parition将一个table的数据分为若干个region。每个region在一个时间点，只可以被一个region
server服务。一个region server可以同时服务多个regions. region和region server的服务映射关系存储在hbase特殊的表meta表里面。

![hbase scalibility]({{BASE_PATH}}/assets/img/hbase-scalibility.png)

  当一个region server crash之后，hmaster会通过zookeeper检测到regionserver失效时间，然后重新分这个region 
server服务的所有region，将这些region迁移的其他机器上， 保证hbase的高可用性。

  随着数据量的增大，现有的机器可能无法服务现有数据，可以通过向集群添加新的机器，实现水平扩展。当hmaster检测到一个新的的region server加入， 会自动发起一个均衡逻辑，将其他region server的region迁移到这台空region server上, 保持这个集群的负载均衡。另外数据量大的region可以手动或者自动的split，分为两个小的region。自动将数据和压力分散到其他机器上。

  region从region server A上迁移到region server, B上过程中，有一段时间region是不可访问的。但是这个时间非常端，一般在s级别.

####读写流程
![hbase write ahead log]({{BASE_PATH}}/assets/img/hbase-WAL.png)

####HMaster HA
HMaster的主要职责region balancer, regionserver的failover，表的管理操作等。
HMaster不参与正常的数据读写流程，因此Hmaster短暂的不可用不会影响hbase的可用性。

HMaster没不存储任何关键信息, hbase路由信息存储在ROOT和META表里面，
表的描述消息存储在分布式文件系统里面， RegionServer/Region状态消息存储在zk上

当主hmaster异常推出时候，
同过zk抢锁/hbase/master的锁，backup的HMaster升级为主，执行Hmaster的控制功能。

因此hmaster不是hbase里面的单点。

####原子性
在一个时间点，任何一个region只能被一个regionserver服务，即对于任何一行的数据，读写操作的入口只有一个regionserver。

在regionserver内部
主要支持row级别的原子性，不支持跨行，跨表的原子性，但支持单个region内部跨row的原子性。
####一致性

强一致性. 写成功之后，所有的client都可以马上读到最新的数据。

####持久性

###高级特性
####二级索引
因为hbase现在还不支持跨行扩表的原子性，所以在hbase还不支持强一致的全局二级索引。
可以利用hbase region内部跨row的原子性来实现强一致的局部二级索引。
对于很多数据以用户为中心的互联网产品数据，通过设置region拆分策略(), 保证一个用户的数据一定落在一个region上，不会跨region。
这样对这个用户跨row的操作就可以保证强一致性。

####mapreduce支持
hbase扩展hadoop mapreduce的输入输出流，使得mapreduce作业可以非常方便的直接读写hbase。

####Coproccsor


###部署
####测试环境
hbase的启动支持mini cluster, standalone,和distributed三种模式。
在测试环境，你可以方便启动一个mini cluster来做单元测试。在onebox环境, 
你可以使用standalone模式，在一个机器上启动一个单节点的hbase，模拟这个系统。
standalone模式和distributed模式区别在hbase使用是本地文件系统而不是hdfs存储数据，
其他方面如数据读写路径都相同

####生产环境
生产环境部署，hadoop依赖hdfs作为分布式文件系统，作为数据的持久化存储，依赖zookeeper提高的分布式锁等服务。在系统层面上， 
还依赖系统ntp服务保证regionserver之间的时钟同步（很多hdfs/hbase依赖租约协议）.对自动化的运维提出很高的要求。

TODO(实际部署的物理视图)

####局部二级索引
see:

http://hadoop-hbase.blogspot.com/2012/02/limited-cross-row-transactions-in-hbase.html

####异步跨机房备份
![hbase replication]({{ BASE_PATH }}/assets/img/hbase-replication.png)
####安全&权限
hadoop/hbase在kerberos认证基础上实现列级别的权限管理，能够保证数据安全，防止非法用户访问。

###hbase社区
hbase社区<https://hbase.apache.org/>非常活跃，有工作在一线的hadoop/hbase开发者。
遇到自己不能解决的问题，在邮件组提问，可以很快得到反馈。社区也在不断修复以前的bug，开发新的特性,
每天在hbase jira可以看到很多task。

###劣势
- hbase构建在hadoop，zookeeper之上，实际部署会遇到很多问题，对于中小的创业公司无法很快掌握这么庞大的系统.因此对于中小公司来说，使用cloudera的发行版是一个很好的选择

###参考资料
- <http://www.slideshare.net/xefyr/h-base-for-architectspptx>

