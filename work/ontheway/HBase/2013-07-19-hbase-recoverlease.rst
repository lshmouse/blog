+--------------------------------+
| layout: post                   |
+--------------------------------+
| title: "hbase recover lease"   |
+--------------------------------+
| category: HBase                |
+--------------------------------+
| tags: [HBase, leaserecover]    |
+--------------------------------+

{% include JB/setup %}

recoverlease的原因
~~~~~~~~~~~~~~~~~~

HBASE-7878: split hlog 过程中recoverlease没有检查返回值， 可能导致丢数据
HBASE-8354: 将HBASE-7878 backport到了hbase 0.94上 HABSE-8204:
去掉了append, while循环不断的recoverlease

死循环的bug
~~~~~~~~~~~

HBASE-8389： 在patch HBASE-8354后，recoverlease进入了死循环

改进办法
~~~~~~~~

HBASE-8389： 在patch HBASE-8354后，recoverlease进入了死循环 HBASE-8449:
重构了 HBASE-8389的代码 HBASE-8670: 将HBASE-8204, HBASE-8449 backport
hbase-0.94分支上

测试
~~~~

同时杀死一个机器上的datanode和regionserver
