vagrant
===============

vagrant 是一个命令行虚拟机管理工具，他可以非常方便的管理虚拟机
参考官网: http://www.vagrantup.com/

安装
-------------

安装virtualbox
^^^^^^^^^^^^^^^

下载virtualbox的最新安装包,
https://www.virtualbox.org/wiki/Linux_Downloads 在centos
5/6直接用yum安装

::

   yum install VirtualBox-4.2

安装vagrant
^^^^^^^^^^^^

下载vagrant安装包：http://downloads.vagrantup.com/tags/v1.2.4,
以rpm包为例

::

    wget http://files.vagrantup.com/packages/0219bb87725aac28a97c0e924c310cc97831fd9d/vagrant_1.2.4_x86_64.rpm
    rpm -i vagrant_1.2.4_x86_64.rpm

使用
-------------

下载虚拟机模板，vagrant使用的模板叫做box, 模板下载地址
http://www.vagrantbox.es

::

    vagrant box add precise64 http://files.vagrantup.com/precise64.box

初始化

::

    mkdir vagrantdemo
    cd vagrantdemo
    vagrant init precise64

启动虚拟机

::

    vagrant up

登录虚拟机

::

    vagrant ssh

关闭虚拟机

::

    vagrant halt

其他文档参见：http://docs.vagrantup.com/v2/

案例
-----------

使用vagrant在单机上进行hadoop/hbase分布式测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
see:
http://blog.cloudera.com/blog/2013/04/how-to-use-vagrant-to-set-up-a-virtual-hadoop-cluster/
