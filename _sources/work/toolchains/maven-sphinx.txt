Maven sphinx 插件
=====================

代码和文档一样重要
---------------------
好的用户使用文档可以显著减少用户接入工作，让开发人员从繁复的业务接入中解脱出来。
怎样保证文档的质量呢？--> 让文档向代码一样可以review,
这就需要文档使用纯文本你编写，而不是word或者wiki。

现在比较流行的纯文本编写文档语言有：Markdown. reStructured等.
sphinx是使用reStructuredText 标记语法的文档编写工具，用户使用纯文本编写，sphinx可以自动生成各种格式的文档。

因为对sphinx更熟悉一些，因此介绍一下如何将sphinx和maven工程整合起来

Maven + sphinx
----------------
安装sphinx
::
  sudo easy_install sphinx

在maven工程下初始化sphinx目录
::
 mkdir -p src/site/sphinx
 cd sr/site/sphinx
 sphinx-quickstart

pom添加sphinx的构建
::  
  <build>
    <plugins>
      <plugin>
        <groupId>org.tomdz.maven</groupId>
        <artifactId>sphinx-maven-plugin</artifactId>
        <version>1.0.3</version>
        <configuration>
          <builder>html</builder>
          <outputDirectory>${project.reporting.outputDirectory}/doc</outputDirectory>
        </configuration>
        <executions>
          <execution>
            <phase>package</phase>
            <goals>
              <goal>generate</goal>
            </goals>
          </execution>
        </executions>
      </plugin>
    </plugins>
  </build>
 
使用reStructured Text编写文档, 参见：http://sphinx-doc.org/

编译：
::
  mvn clean packgae
输出在target/site/doc

启动http服务
::
  cd target/site/doc
  python -m SimpleHTTPServer

参考
---------
- 参考: https://github.com/tomdz/sphinx-Maven
- 例子：https://lshmouse@bitbucket.org/lshmouse/sphinx-maven.git
