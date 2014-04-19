JVM编译
============
下载代码
--------
hg clone http://hg.openjdk.java.net/jdk6/jdk6/hotspot/ hotspot

编译
--------
:: 
   cd make
   make product/jvmg LP64=1 ALT\_BOOTDIR=$JAVA\_HOME HOTSPOT\_BUILD\_JOBS=8

等待编译完成. 完成后新生成的libjvm在:hotspot/build/linux/linux\_amd64\_compiler2/product/libjvm.so

替换当前jdk的jvm cp
::
   hotspot/build/linux/linux\_amd64\_compiler2/product/libjvm.so ${JAVA\_HOME}/jre/lib/amd64/server/

验证， 查看jvm的版本
:: 
   java -version

参考
----

*http://jvm.taobao.org/index.php/Build\_TaobaoJVM%E7%9A%84%E6%96%B9%E6%B3%95*http://www.slideshare.net/RednaxelaFX/hotspot-vm20120303
\*http://en.wikipedia.org/wiki/HotSpot

sun jdk/ open jdk / HotSpot VM 对应表
\*https://gist.github.com/rednaxelafx/925323
