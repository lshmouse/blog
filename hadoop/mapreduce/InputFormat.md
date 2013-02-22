Hadoop MapReduce InputFormat
=============================

Hadoop Mapreduce支持多种输出格式：Text, SequenceFile, HFile等， 本文主要讨论：
- hadoop支持那些文件格式
- hadoop是怎么实现对多种文件格式的输入(接口设计，类层次关系等)
- 典型的文件格式Text, SequenceFile, HFile等，是怎么切分的，来保证记录的完整性
- 怎么实现自定义的文件格式

Hadoop 支持的文件格式
-----------------------

