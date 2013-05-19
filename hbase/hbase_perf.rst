Hbase Performance
=====================================

Write(autoflush=true)
---------------------
latency: 1-3ms
qps: 1-10k per node

### 影响write性能的因素

Read
--------------------
From Cache, latency: 0-3ms 
From Flash, latency: 1-3ms
From Disk,  latency: ~10 ms

### 影响write性能的因素
(1) cache 命中率
(2) hfile个数


其他因素
--------------------------
(1) 传输加密
