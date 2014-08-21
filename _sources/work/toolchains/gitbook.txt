GitBook
=================================
GitBook是一个命令行工具（Node.js库） 借用该工具使用Github/Git和Markdown, 可以来来制作精美的图书。
GitBook支持输出多种文档格式： 静态站点(可以托管在github gh-pages上)， pdf，电子书等等

安装
------------
安装: nodejs
::
  sudo apt-get install node

安装: gitbook库
::
  sudo npm install -g gitbook

测试gitbook 命令:
::
  gitbook

Startup
------------
使用GitBook制作电子书，必备两个文件：README.md和SUMMARY.md。
README.md多为电子书的简介内容，SUMMARY.md用来定义电子书章节结构，如：

SUMMARY.md例子:
::

  # Summary

  * [chapter 1](chapter1/README.md)
      * [Lesson 1](chapter1/lesson1.md)
      * [Lesson 2](chapter1/lesson2.md)

初始化git项目:
::
  gitbook init 

使用gitbook编译:
::
  gitbook build

本地查看电子书:
::
  gitbook serve

浏览器打开http://localhost:4000/即可查看生成的电子书

生成pdf
::
  gitbook pdf

demo 参见： https://github.com/lshmouse/gitbook-demo

发布到gitbook.io上
-------------------
在gitbook.io上创建账户和一本电子书，例如用户是username, 电子书是: demo

将本地电子书关联到远程
::
   gitbook git:remote . username/demo

发布电子书
::
  gitbook publish

查看电子书: http://usename.gitbooks.io/demo/

发布到github pages上
--------------------
创建或者clone一个gh-pages分支
::
  mkdir .tmp
  cd .tmp
  git clone https://github.com/lshmouse/gitbook-demo.git
  cd gitbook-demo 
  git checkout -b gh-pages

清空旧数据，导入新数据:
:: 
  git rm *
  cp -r ../../_books/* .
  git add .
  git commit -m "pushlish to gh-pages"

将本地分支推送到远端
::
 git push origin gh-pages
 cd ../../
 rm -rf .tmp

还可以使用grunt,将上面任务自动化。参见:
http://rorlab.gitbooks.io/rorla/contents/references/gitbook_deployment.html

参考
-----------
- GitBook https://www.gitbook.io/
- GitBook code https://github.com/GitbookIO/gitbook
