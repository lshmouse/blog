+---------------------------+
| layout: post              |
+---------------------------+
| title: "hbase bulkload"   |
+---------------------------+
| description: ""           |
+---------------------------+
| category: HBase           |
+---------------------------+
| tags: [HBase]             |
+---------------------------+

{% include JB/setup %}

参考：http://hbase.apache.org/book.html#arch.bulk.load

importtsv是使用mapreduce批量导入数据到hbase的工具。importtsv的输出方式有两种，一种是直接写入hbase，另外一种是先将数据写成hfile格式，
然后使用 completebulkloads 工具将这些 hfile
复制到对应region的hfile目录，然后通知hbase把这些hfile的数据加载起来。第一种方式直接一些，一个mapreduce作业就可以完成，第二种方式效率更高，需要两步来完成。

为了将tsv格式文件数据导入hbase，需要一个映射关系，即tsv里面的列 和hbase
row key /cf:qualifier对应关系。 通过-Dimporttsv.columns=
选项指定，顺序需要和tsv里面列对应，另外需要指定一个列作为hbase row
key.用HBASE\_ROW\_KEY标识。
现在importtsv不直接支持tsv里面的多个列映射为一 个row key,
如这种类型的row key: {columnA}-{columnB}-{columnC}，
可以提前处理一下tsv文件，将columnA，columnB，
columnC合为{columnA}-{columnB}-{columnC}

使用手记
--------

数据文件
~~~~~~~~

::

    # cat user-info.txt
    userId name  age  sex
    1 Jim    24   M
    2 Bob    26   F
    3 Robert 24   M
    ...

使用配置好的hadoop集群包， 然后上传数据到hdfs

::

    bin/hdfs dfs -copyFromLocal user-info.txt /user/liushaohui/

hbase schema
~~~~~~~~~~~~

.. raw:: html

   <table class="table table-bordered table-striped table-condensed">
      <tr>
         <td>

row

.. raw:: html

   </td>
         <td>

ColumnFamily

.. raw:: html

   </td> 
         <td>

Column

.. raw:: html

   </td>
         <td>

version

.. raw:: html

   </td> 
         <td>

value

.. raw:: html

   </td>
      </tr>
      <tr>
         <th rowspan="4">

userid

.. raw:: html

   </th>
         <th rowspan="4">

I

.. raw:: html

   </th>
         <td>

info

.. raw:: html

   </td>
         <td> 

1

.. raw:: html

   </td>
         <td> 

数据

.. raw:: html

   </td>
      </tr>
      <tr>
         <td> 

name

.. raw:: html

   </td>
         <td> 

1

.. raw:: html

   </td>
         <td> 

数据

.. raw:: html

   </td>
      </tr>
      <tr>
         <td>

age

.. raw:: html

   </td>
         <td> 

1

.. raw:: html

   </td>
         <td> 

数据

.. raw:: html

   </td>
      </tr>
      <tr>
         <td>

sex

.. raw:: html

   </td>
         <td> 

1

.. raw:: html

   </td>
         <td>

数据

.. raw:: html

   </td>
      </tr>
   </table>

映射关系
~~~~~~~~

::

    userid -> HBASE_ROW_KEY
    name-> I:name
    age-> I:age
    sex -> I:sex

下载配置好的hbase集群发布包创建表（在安全集群，普通用户没有建表权限）：

::

    bin/hbase shell
    create 'test-user-info', { NAME => 'I', VERSIONS => '1', BLOOMFILTER => 'ROW', COMPRESSION => 'SNAPPY', COMPRESSION_COMPACT => 'SNAPPY', REPLICATION_SCOPE => 1 }

直接写入hbase
~~~~~~~~~~~~~

使用ImportTsv导入数据:

::

    bin/hbase org.apache.hadoop.hbase.mapreduce.ImportTsv -Dimporttsv.columns=HBASE_ROW_KEY,I:name,I:age,I:sex test-user-info /user/liushaohui/user-info.txt

mapreduce作业成功：

::

    13/07/31 15:37:57 INFO mapreduce.Job:  map 100% reduce 0%
    13/07/31 15:37:57 INFO mapreduce.Job: Job job_1373456666633_25299 completed successfully
    13/07/31 15:37:57 INFO mapreduce.Job: Counters: 28

验证 运行

::

    bin/hbase shell
    hbase(main):004:0> scan 'test-user-info'
    ROW                                            COLUMN+CELL                                                                                                                         
    1                                            column=I:age, timestamp=1375256276218, value=24                                                                                     
    1                                            column=I:name, timestamp=1375256276218, value=Jim                                                                                   
    1                                            column=I:sex, timestamp=1375256276218, value=M                                                                                      
    2                                            column=I:age, timestamp=1375256276218, value=26                                                                                     
    2                                            column=I:name, timestamp=1375256276218, value=Bob                                                                                   
    2                                            column=I:sex, timestamp=1375256276218, value=F                                                                                      
    3                                            column=I:age, timestamp=1375256276218, value=24                                                                                     
    3                                            column=I:name, timestamp=1375256276218, value=Robert                                                                                
    3                                            column=I:sex, timestamp=1375256276218, value=M

生成hfile再导入
~~~~~~~~~~~~~~~

当指定选项-Dimporttsv.bulk.output后，ImportTsv程序会直接生成hfile,根据table当前region范围来分区，每一个region对于一个reduce，每个column
family一个文件

::

    bin/hbase org.apache.hadoop.hbase.mapreduce.ImportTsv -Dimporttsv.bulk.output=/user/liushaohui/user-output -Dimporttsv.columns=HBASE_ROW_KEY,I:name,I:age,I:sex test-user-info /user/liushaohui/user-info.txt

结果：

::

    13/07/31 15:59:36 INFO mapreduce.Job:  map 0% reduce 0%
    13/07/31 15:59:41 INFO mapreduce.Job:  map 100% reduce 0%
    13/07/31 15:59:46 INFO mapreduce.Job:  map 100% reduce 100%
    13/07/31 15:59:46 INFO mapreduce.Job: Job job_1373456666633_25339 completed successfully

hdfs:

::

    bin/hadoop dfs -ls /user/liushaohui/user-output
    Found 2 items
    drwxr-xr-x   - liushaohui supergroup          0 2013-07-31 15:59 /user/liushaohui/user-output/I
    -rw-r--r--   3 liushaohui supergroup          0 2013-07-31 15:59 /user/liushaohui/user-output/_SUCCESS

让hbase 加载对于hfile文件.

LoadIncrementalHFiles工具通过region
server将生成的hfile文件通过文件系统的rename机器导致hdfs对于目录，然后通知region加载这个hfile。
因此需要保证运行hbase region server的用户对需要导入的数据目录有读写权限

::

    bin/hbase org.apache.hadoop.hbase.mapreduce.LoadIncrementalHFiles /user/liushaohui/user-output test-user-info

结果：

::

    bin/hbase shell
    hbase(main):002:0> scan 'test-user-info'
    ROW                                            COLUMN+CELL                                                                                                                         
    1                                            column=I:age, timestamp=1375257579771, value=24                                                                                     
    1                                            column=I:name, timestamp=1375257579771, value=Jim                                                                                   
    1                                            column=I:sex, timestamp=1375257579771, value=M                                                                                      
    2                                            column=I:age, timestamp=1375257579771, value=26                                                                                     
    2                                            column=I:name, timestamp=1375257579771, value=Bob                                                                                   
    2                                            column=I:sex, timestamp=1375257579771, value=F                                                                                      
    3                                            column=I:age, timestamp=1375257579771, value=24                                                                                     
    3                                            column=I:name, timestamp=1375257579771, value=Robert                                                                                
    3                                            column=I:sex, timestamp=1375257579771, value=M

总结，bulkload工具在将离线处理的结构化数据批量导入hbase，然后服务线上业务还是非常方便的。
