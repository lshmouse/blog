Git 基本操作
======================

全局设置
--------------------
查看所有全局设置
::
 git config --list 

设置git用户名
::
  git config --global user.name usename

设置git用户邮箱
::
  git config --global user.email email

设置文本编辑器
::
  git config --global core.editor emacs

设置merge工具
::
 git config --global merge.tool vimdiff 

Basic
~~~~~~~~~~~~~~~~~~~
clone一个项目
::
  git clone git-repos

项目更新
::
  git pull

删除上一个commit
::
  git reset --hard HEAD^

把几次提交合为一个
::
  git reset --soft HEAD~4
  git commit -a

删除本地所有未提交的更改
::
  git clean -df
  git reset --hard

当前分支所有的diff
::
  git diff master

修改上一次提交的注释
::
 git amend

分支回滚到某一次提交
::
 git reset --hard commit-id 

合并其他分支提交到本分支
::
 git cherry-pick commit-A
 git cherry-pick commit-A..commit-B

Branch
--------------
查看本地所有分支
::
  git branch -a

创建本地分支
::
  git checkout -b branch-name

根据远程分支创建本地分支
::
  git checkout -b branch-name origin/branch-name

将本地分支修改推送到远程
::
  git push origin branch-name 

重命名一个分支
::
  git branch -n branch-name new-branch-name

删除一个本地分支
::
 git branch -d branch-name
 or 
 git branch -D branch-name

删除一个远程分支
::
 git push origin --delete branch-name
 or 
 git push origin :branch-name

Tag
--------------
查看本地所有Tag
::
  git tag -l

根据远程Tag创建本地分支
::
  git checkout -b tag-name tag/tag-name

将本地tag修改推送到远程
::
  git push origin tag-name 

当前分支所有的diff
::
  git diff master

删除一个远程分支
::
 git push origin --delete tag-name
 git push origin :tag-name

Patch
---------------
生成所有patch列表
::
 git format-patch --root master .

检查patch是否可以打成功
::
 git apply --check $PATCH

upstream
------------
添加一个上游分支
::
 git remote add upstream upstream-repos 
 git fetch upstream

rebase上游分支
::
 git rebase upstream/trunk

rebase上游分支, 并合并某次提交之后的代码
::
 git rebase --onto upstream/branches commit-id

参考
---------------
- Pro Git http://git-scm.com/book/zh 
