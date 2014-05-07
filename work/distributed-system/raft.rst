Raft
========

MemberShip
------------

Log
------------

State Machine
------------


读写路径
------------
调用Server.Do(command Command) 
-->  server.send(value interface{}), 将Command转化为一个事件传递给Server的channel
-->  等待事件的channel上 

leader在leadloop中select事件
-->  server.leaderloop() 收到command事件
-->  server.processCommand 处理事件
-->  log.appendEntry(entry) 写到log的entry 队列里面

leader记录所有peer状态, 通过定时的heartbeat
--> peer.heartbeat() 调用flush
--> peer.flush() 从leader的entry队列里面获取entry，构造出AppendEntriesRequest
--> peer.sendAppendEntriesRequest() 将log entries发给follower,candidate
注： 一次可以发送多个entries，这里没有追赶log entries的逻辑,都是leader主动发给follower的

follower/Candidate收到AppendEntriesRequest
--> server.processAppendEntriesRequest, 处理同意或者拒绝,返回AppendEntriesResponse

leader收到AppendEntriesResponse
--> server.processAppendEntriesResponse 处理，如果多数peer统一这个entry
--> log.setCommitIndex(), 则通过事件的channel 通知调用者成功

参考
------
* http://blog.gopheracademy.com/writing-a-distributed-system-library
* http://raftconsensus.github.io/
