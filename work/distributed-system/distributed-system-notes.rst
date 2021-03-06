分布式系统一些心的
====================
(注：这是微软的杨冒大神来小米演讲之后的感触和思考）

Paxos协议成为标配
-------------------
强一致性对上层应用开发者友好，这早已是一个基本共识。
但是长久以来大家实现分布式存储系统很多都是弱一致性的。主要是觉得实现一个强一致性的协议比较难，所以退而求其次。

随着慢慢更多的人研究Paxos协议及其实现，以及paxos的更好实现的变种raft,
Paxos慢慢被跟多的分布式系统开发者所熟悉和掌握, 来解决分布系统里面解决一致性和可用性的权衡问题。
如多副本强一致问题，跨机房的强一致问题。

有兴趣的同学可以参考一下goraft(https://github.com/goraft/raft)
核心不过1K行代码，怎么实现一个强一致性协议原型。只所以说原型，是因为其中还有很多需要优化点,
到工程实用还需要做很多优化.但至少给一个感受实现这样协议并不难，关键在于理解协议的精髓。

分层架构和竖井架构
-------------------
分层架构是整个分布式存储系统被分为多层，每一层对上层提供基本的服务和保证，并对上层透明的。
上层使用下次提供的服务和保证来实现自己这一层的服务，这样这一曾的分布式逻辑会简单很多。
典型的例子是google的GFS/BigTable系统，GFS实现一个分布式文件系统层，Bigtable基于GFS实现分布式数据库. 
GFS在Bigtable看来就是大硬盘，Bigtable将数据存储在GFS，至于数据是怎么存放的BigTable并不需要太多关心。
分层架构的优点是：每一层基于下一层的假设，只需要关注本层逻辑，实现起来工程复杂度会小很多。
缺点是：因为下层对上层是透明的，上层对下层的行为很难控制，很容易造成下层资源竞争，使得系统的延时很难控制。
无法满足实时性要求比较高的业务需求。

竖井架构是指从分布式曾到单机操作系统层（更有甚者直接跳过操作系统，直接读写存储介质）都有一个系统来控制。
所有的IO都由系统统一控制, 系统资源的可控行更强，因此延时更好控制。很多分布式的kv系统都是采用这种竖井架构。

随着更多实时性需求，会有更多系统尝试竖井架构 + Paxos协议。


多种存储引擎
-------------------
我所知有两大类存储引擎： B+类和Merge-Dump类。B+树类写的时候是一个随机写，适合于写少读多的场景。
Merge-Dump类将写转化为append写，但是读的时候需要做合并，适合于写多读少的场景。
业务需求是变化多样的，很难用一个存储引擎支持所有业务。但是为每一类存储引擎实现一套分布式存储系统将不太现实的。

另外一个思路是怎样把存储引擎从分布式存储系统里面抽象出来，保持上层分布式架构和一致性协议不变，下层的存储引擎做成可配置的。
根据不同的业务需求，选择不同的存储引擎。

听着很简单，但是实践起来会有非常多的问题。这种抽象需求很强系统设计的功底,并对分布式系统有非常深刻的理解。
