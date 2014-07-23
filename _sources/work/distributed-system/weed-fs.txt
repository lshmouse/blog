weed-fs
===================

weed-fs是Go语言实现的，类facebook haystack的面向blob的分布式存储系统.

上周从Quora问题 
http://www.quora.com/What-is-a-good-choice-for-storing-blob-like-files-in-a-distributed-environment
下面的回答中发现。最近比较关注Go语言以及GO实现的一些分布式系统，因此将代码下载下来研究了一下。

项目地址
---------------
https://code.google.com/p/weed-fs/

项目wiki中有特性介绍，请移步自己看～

主要特点
---------------
* 类facebook haystack, 面向blob的对象存储
* Master-Worker架构。 Blob存储在物理volume,
  一个worker上包含很多物理卷，这个物理卷 + 数据存放策略组成逻辑卷，Master管理这些逻辑卷
* Master使用raft协议保证无单点故障
* 灵活blob存放策略，支持数据中心+ 同数据中心不同机架+ 同数据中心同机架

编译
--------------
安装依赖:
::

 go get bazil.org/fuse/
 go get github.com/disintegration/imaging/
 go get github.com/goraft/raft/
 go get github.com/gorilla/mux
 go get github.com/rwcarlsen/goexif
 go get github.com/syndtr/goleveldb
 go get github.com/tgulacsi/go-cdb/

下载代码后编译
::

  go get code.google.com/p/weed-fs/
  go build go build code.google.com/p/weed-fs/go/weed

搭建测试集群
---------------
首先启动master, 在启动volume server(数据中心dc1中, 机架rack1上两个节点，
机架rack2上一个几点。数据中心dc2上，机架rack3上一个节点)

::
 
 # start weed master
 ./weed master > master.log 2>&1 &
 
 # start weed volume server
 mkdir -p demo/data1
 ./weed volume -dir=demo/data1 -max=5 -mserver=localhost:9333 -port=8080 -dataCenter=dc1 -rack=rack1 > node-1.log 2>&1 &

 mkdir -p demo/data2
 ./weed volume -dir=demo/data2 -max=5 -mserver=localhost:9333 -port=8081 -dataCenter=dc1 -rack=rack1 > node-2.log 2>&1 &

 # datanode in different rack, but same data center
 mkdir -p demo/data3
 ./weed volume -dir=demo/data3 -max=5 -mserver=localhost:9333 -port=8082 -dataCenter=dc1 -rack=rack2 > node-3.log 2>&1 &
 
 # datanode in different data center
 mkdir -p demo/data4
 ./weed volume -dir=demo/data4 -max=5 -mserver=localhost:9333 -port=8083 -dataCenter=dc2 -rack=rack3 > node-4.log 2>&1 &

简单测试
---------------

*上传文件*

* 分配文件ID. 文件ID = volume ID + file key + 校验码
::

  $ curl http://localhost:9333/dir/assign
  {"fid":"27,0498cb603b","url":"127.0.0.1:8081","publicUrl":"localhost:8081","count":1}

同时可以指定数据放置策略
::
  
  $ curl http://localhost:9333/dir/assign?replication=011 
  {"fid":"20,05551858e0","url":"127.0.0.1:8081","publicUrl":"localhost:8081","count":1}

防止策略参见：https://code.google.com/p/weed-fs/wiki/RackDataCenterAwareReplication

* 上出文件
	根据返回的文件ID，构造volume server上传地址，上传数据
::
  
  $ curl -F @hello.txt http://127.0.0.1:8081/20,05551858e0 
  {"size": 43234}

*下载文件*

根据volume id, 从Master查询volume所在server地址
::

 $ curl http://localhost:9333/dir/lookup?volumeId=20
 {"volumeId":"20","locations":
   [{"url":"127.0.0.1:8081","publicUrl":"localhost:8081"},
    {"url":"127.0.0.1:8080","publicUrl":"localhost:8080"},
    {"url":"127.0.0.1:8083","publicUrl":"localhost:8083"}
   ]
 }

客户端可以根据返回volume server地址选择一个（如选择一个同数据中心,最近的）构造下载地址
::

  $ curl http://127.0.0.1:8083/20,05551858e0

volume的一致性
-----------------
一个逻辑卷有一个确定数据存放策略，根据存放策略，一个逻辑卷包含一个或者多个逻辑卷。
怎么保持这些逻辑卷的同步呢？

现在实现是同步协议。当请求发到一个volume server上之后，
这个server将数据在转发到这个逻辑卷的其他卷服务器上去，当数据在所有物理卷上都成功之后，才返回给客户端成功。

这个实现会造成:
* 一个逻辑卷里面各个物理卷的数据不一致，某些卷里面会与脏数据.
* 如果一个物理卷不可用的时候，整个逻辑卷都是不可写。

可以使用raft协议来世实现逻辑卷的一致性。

