Paxos
==========================

Basic Paxos
-----------------
基本Paxos是解决多个线程或者进程在单个变量上达成一致的分布式算法. 
参考： http://research.microsoft.com/en-us/um/people/lamport/pubs/paxos-simple.pdf

Multi Paxos
-----------------
Mutli-Paxos是Basic Paxos的扩展，是解决分布在不同位置的数据集上达成一致的分布式算法.
Raft即是Multi-Paxos算法的一种实现。

重新选主恢复的问题 -> 需要退回到Basic Paxos直到

Master lease避免读请求走一遍

参见： http://research.microsoft.com/en-us/um/people/lamport/pubs/paxos-simple.pdf

参考
----------------
- https://blog.treode.com/ 
