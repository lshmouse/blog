大规模监控报警系统
=========================

参考
--------
http://www.slideshare.net/quipo/

https://github.com/monigusto/vagrant-monigusto

传统: ganglia, nagios
---------------------

缺点: 不能支持足够大的规模

skyline
-------

http://codeascraft.com/2013/06/11/introducing-kale/

OpenTSDB
--------

http://opentsdb.net

优势： 扩展性强

Linkedin
--------

Using kafka for Metrics aggeration

https://engineering.linkedin.com/52/autometrics-self-service-metrics-collection

Design
------

(1) 原始数据客户端通过代理，直接写入Hbase
(2) 代理层会将原始数据写入消息队列kafka,
    Aggerator作为kafka的消费者聚合采样数据，然后写入HBase(采用率可以设置为10s,
    1m, 5m, 1m, 1d), (最大，最小，平均值)
(3) 前端查询通过时间范围自动计算采样率，然后从HBase里面scan出数据

