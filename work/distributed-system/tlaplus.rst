TLA+
========================

开始关注TLA+, 是从Amazon的博文：formal-methods-amazon, 文章介绍Amazon的工程师使用TLA+描述Amazon内部的分布式系统
S3, DynamoDB等，来验证原型的准确性，并找出原型上的bugs

Specification是对一个系统模型的描述, 系统模型主要包含状态和转移两部分.
TLA+就是一种描述Specification的语言， 以及对模型检测.

安装工具包
-------------------
源代码：http://tlaplus.codeplex.com/

下载https://tla.msr-inria.inria.fr/tlatoolbox/products/

Ubuntu上启动:
::
  #!/bin/bash
  export UBUNTU_MENUPROXY=0 
  toolbox/toolbox

PlusCal
------------------------
+Cal是一种类似C语言的描述语言, TLA+ toolbox可以将+Cal写的程序转化为TLA+ 语言，然后进行模型检测。
对程序员来说，+Cal更容易理解和使用。


First demo
----------------------
::
  VARIABLE b
  Init== (b=0) \/ (b=1)
  Next == \/ /\ b = 0 
             /\ b' = 1
          \/ /\ b = 1
             /\ b' = 0

Check 条件:
  b \in {0, 1}


To be continued

例子
----------------------------
raft protocal https://github.com/wayoutmind/melee/blob/master/docs/

参考
-------
- formal-methods-amazon http://research.microsoft.com/en-us/um/people/lamport/tla/formal-methods-amazon.pdf
- http://tla2012.loria.fr/contributed/newcombe-slides.pdf
- TLA home page http://research.microsoft.com/en-us/um/people/lamport/tla/tla.html
- The TLA+ Hyperbook http://research.microsoft.com/en-us/um/people/lamport/tla/hyperbook.html
- TLA toolbox http://research.microsoft.com/en-us/um/people/lamport/tla/toolbox.html
- PlusCal http://research.microsoft.com/en-us/um/people/lamport/tla/pluscal.html
