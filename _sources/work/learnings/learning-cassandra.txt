Cansandra初探
==============

编译
~~~~~

先安装jdk7, cassandra要求jdk版本>1.7. why?

::

    sudo apt-get install openjdk-7-jdk7

安装和配置ant, maven. 下载ant， maven的二进制包

::

    wget http://mirrors.tuna.tsinghua.edu.cn/apache//ant/binaries/apache-ant-1.9.2-bin.zip
    unzip apache-ant-1.9.2-bin.zip
    wget http://mirrors.tuna.tsinghua.edu.cn/apache/maven/binaries/apache-maven-3.0.5-bin.zip
    unzip apache-maven-3.0.5-bin.zip

将ant，maven导入环境变量，在~/.bashrc添加

::

    export MAVEN_HOME=/PATH/apache-ant-1.9.2
    export PATH=$PATH:$MAVEN_HOME/bin/

    export ANT_HOME=/PATH/apache-maven-3.0.5
    export PATH=${PATH}:${ANT_HOME}/bin/

配置maven的setings.xml文件， 如果不知道这个是何物，请先学习一下maven

使用ant编译：

::

    ant

将项目导入eclipse工程

::

    ant generate-eclipse-files

然后使用eclispse导入java项目

本地版启动
~~~~~~~~~~

架构
~~~~

http://wiki.apache.org/cassandra/ArchitectureInternals
http://www.slideshare.net/NinGoo/cassandra-4586176

数据流
^^^^^^

写流程
''''''

读流程
''''''

容错与一致性hash
^^^^^^^^^^^^^^^^

读修复
''''''

Anti-Entropy Node Repair
''''''''''''''''''''''''

优化:hinted Handoff
'''''''''''''''''''

