1.  `介绍LinuxContainer和Cgroup文章： <http://www.ibm.com/developerworks/cn/linux/l-lxc-containers/#resources>`_
    主要用于轻量级的虚拟化，与虚拟机比较：资源利用率比较高，但是隔离效果没有虚拟机好，现在linux内核支持cpu和内存的隔离，可能还需要网络，和磁盘读写的隔离。

2.  关于GFS设计的一个访谈：`GFS: Evolution on
    Fast-forward <http://queue.acm.org/detail.cfm?id=1594206>`_。从这篇访谈里面可以了解GFS的设计初衷，思路，以及面临的问题，GFS不是万能的，他也只是适合特定的场景。

3.  一个在线合作编辑的网站：`http://collabedit.com/ <http://collabedit.com/>`_。
    特点在于支持多种语言，并且有语法高亮，速度也不错，前段时间用于电话面试，效果还行。

4.  `Hadoop中TeraSort算法分析 <http://dongxicheng.org/mapreduce/hadoop-terasort-analyse/>`_。讲的比较清晰，详细。但是要做到yahoo做的hadoop
    的teresort
    benchmark的62s，还是做了特殊的优化的，有想去可以搜索一下，对这些优化的理解可能进一步提高你对mapreduc框架的理解。最后是sort
    benchmark的网站，有兴趣看一看：`http://sortbenchmark.org/ <http://sortbenchmark.org/>`_

5.  一个开源的codereview平台：`rietveld <http://code.google.com/p/rietveld/>`_。
    我们team一直在用，对保证代码质量还是很有帮助的。另附：`google-styleguide <http://code.google.com/p/google-styleguide/>`_ 
    因为开发c++多一些，对c++ google
    style还是很佩服的，里面的要求是很有道理的。对于c++，如果你不想看英文：推荐`http://code.google.com/p/zh-google-styleguide/ <http://code.google.com/p/zh-google-styleguide/>`_
    或者直接看这里：`http://codinn.com/projects/google-cpp-styleguide/view/ <http://codinn.com/projects/google-cpp-styleguide/view/>`_
    不仅将规范还将为什么，很佩服。

6.  编程基本操作的奇巧淫技
    ：`http://aggregate.ee.engr.uky.edu/MAGIC/ <http://aggregate.ee.engr.uky.edu/MAGIC/>`_。
    比如说不用比较求两个数的最小值，
    快速判断一个数是否是2的幂，还是很有趣的。

7.  分布式操作系统condor：`http://www.cs.wisc.edu/condor/ <http://www.cs.wisc.edu/condor/>`_。
    我现在在用类似的一个系统，这个系统统一管理集群的cpu，内存，磁盘等等资源，按照作业需求分配，提供自动的调度和容错，虽然在一些问题如分布式debug，分布式测试等方面不是特别好，但是这将是一个大趋势，将大大提高机器资源的利用率（一般web2.0网站的机器利用率可能30%都不到），并且让开发者从机器上解放出来。

8.  Django book
    中文翻译：`http://djangobook.py3k.cn/ <http://djangobook.py3k.cn/>`_。
    一个很好的Django文档翻译，一直不喜欢做web，前段时间不得不做一个性能分析的展示页面,
    开始学习和使用Django，感觉很好，把web开发者从繁琐的设置中解脱出来。

9.  Hadoop
    mapreduce框架中文教程：`http://hadoop.apache.org/common/docs/r0.20.0/cn/mapred\_tutorial.html <http://hadoop.apache.org/common/docs/r0.20.0/cn/mapred_tutorial.html>`_。
    对hadoop
    mapreduce的介绍的很详细，很多细节只有你自己去开发之后才能领略到他设计的巧妙。当然如果对mapreduce不了解的话请先看`google的论文 <http://static.googleusercontent.com/external_content/untrusted_dlcp/labs.google.com/en//papers/mapreduce-osdi04.pdf>`_.
    中文翻译也还好：`http://blog.csdn.net/active1001/article/details/1675920 <http://blog.csdn.net/active1001/article/details/1675920>`_

10. Buildbot
    一个开源持续集成平台：`http://trac.buildbot.net/ <http://trac.buildbot.net/>`_。
    Python写的，可扩展性比较强，chrome开发就是用的buildbot。持续集成可以减少开发者在运行测试上浪费的时间，通过自己配置，定期自动执行单元测试，集成测试以及回归测试等，保证项目可用性。appache开源了`hudson <http://hudson-ci.org/>`_：,
    java写的公司内部在使用。

