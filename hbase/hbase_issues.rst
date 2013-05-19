Hbase issues
============================

Too many Hlogs
------------------------
Reason: diff regions with diff loads. And the region with little load will
block the delete of hlogs.

Solution: (1) A backend thread to cleanup the entries in the hlogs which had 
been flushed to fileSytem.


Hbase Compaction
-----------------------
Tier based compaction: https://issues.apache.org/jira/browse/HBASE-6371
upport level compaction: https://issues.apache.org/jira/browse/HBASE-7519

