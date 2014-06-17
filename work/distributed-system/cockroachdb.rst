cockroachdb
=====================
用 raft + rocksdb(leveldb) 做出一个分布式的Datastore 

http://github.com/cockroachdb/cockroachdb

编译
-----------
rocksdb使用c++11部分语法，需要g++4.7以后才能编译。在ubunut下安装g++ 4.7参考
http://askubuntu.com/questions/271388/how-to-install-gcc-4-8-in-ubuntu-12-04-from-the-terminal

  go get github.com/cockroachdb/cockroach
  cd $GOPATH/src/github.com/cockroachdb/cockroach
  ./bootstrap.sh
  make

在当前目录下生成cockroach
注：由于cockroach工程目录不规范，如果使用
  
  git clone https://github.com/cockroachdb/cockroach.git 
  cd cockroach
  ./bootstrap.sh
  make
会报找不到cockroach/server, 解决办法是可以自己修改一下Makefile,
将当前目录加到GOPATH里面

单机版启动
-------------

  ./cockroach init hdd=/data zone.cfg
	./cockroach start -data _dirs=/data -gossip_bootstrap=127.0.0.1:9001

客户端访问


集群配置
--------------------

