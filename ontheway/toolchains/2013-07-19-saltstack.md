---
layout: post
category : toolchains
tags : [saltstack]
---
{% include JB/setup %}

### 介绍
saltstack 是一个轻量机的远程命令执行工具. 相对与puppet/chef，
saltstack轻量，简单，方便配置，而且是一个简单的命令行工具，方便使用。


### 安装
参考：<http://wiki.saltstack.cn/reproduction/om-auto-salt#salt.2BdoRbiYjF->

#### 服务端
    yum install salt-master

启动

    /etc/init.d/salt-master start

####客户端
  
    yum install salt-minion -y

修改配置文件:/etc/salt/minion

    sed -i "s/#master: salt/master: salt-master-ip/" /etc/salt/minion
启动：

    /etc/init.d/salt-minion start
master端接受key：

    salt-key -A
重启

    /etc/init.d/salt-minion start
###用例
####修改crontab里面log修改时间24小时 改为72 小时

    salt '*' cmd.run "crontab -l > /tmp/crontab.bak; sed -i 's/24 /72 /' /tmp/crontab.bak; crontab /tmp/crontab.bak"
####查看磁盘使用情况
    
    salt '*' cmd.run "df -al"

