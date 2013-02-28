How to use ExampleBuilder Plugin
=================================

From: http://www.topcoder.com/contest/classes/ExampleBuilder/ExampleBuilder.html

ExampleBuilder is a CodeProcessor plug-in that, given a ProblemComponentModel, 
produces code to test the examples in the target language.

The plug-in expects a JVM version 1.4 or later.

The plug-in has been in use for nearly a year in its current incarnation (its 
previous version that used a parser was in use for about a year before then). 
I did most of my testing using C# problems. I verified compatibility with Java 
and C++ on a handful of examples, but no extensive testing has been done.

ExampleBuilder comes with code templates for Java, C++, and C#. The plug-in 
defines a $MAINBODY$ variable used in the templates. Code templates are 
important part of the plug-in Ð you must configure your FileEdit with a version 
derived from one of the templates supplied with the plug-in.

Installing ExampleBuilder
------------------------------

To install ExampleBuilder, you need to install CodeProcessor, and configure it
with an editor of your choice. See instructions below for configuring
CodeProcessor to use ExampleBuilder and FileEdit.

# Download the latest CodeProcessor.jar, FileEdit.jar, and ExampleBuilder.jar
from the TopCoder's web site
#Start the TopCoder Arena applet
#From the Options menu, choose Editor to open Editor Preferences
#In Editor Preferences, Click [Add]
#Enter Name = ExampleBuilder
#Enter EntryPoint = codeprocessor.EntryPoint
#Enter ClassPath =
<download>/CodeProcessor.jar;<download>/FileEdit.jar;<download>
ExampleBuilder.jar, where <download> represents an absolute path to the
directory to which you downloaded the jar files.
#In Editor Preferences, select ExampleBuilder, and click [Configure] to open
CodeProcessor Configuration
#Enter Editor EntryPoint = fileedit.EntryPoint
#Enter ProcessorClass = tc_plugin.ExampleBuilder
#In CodeProcessor Configuration, click [Verify]. The applet should detect that
preprocess and getUserDefinedTags methods are present.
#In CodeProcessor Configuration, click [Configure] to access FileEdit's
configuration page. Make a code template that uses the $MAINBODY$ tag to see the
code that ExampleBuilder generates.
#Click [Save] and [Close] in all open dialogs
#Depending on your language preference, download CodeTemplate.java,
CodeTemplate.cpp, or CodeTemplate.cs. Paste the text of the desired template in
the FileEdit's configuration window.
#If you are running WebStart application, close it; if you are running in a
browser, close the instance of the browser that runs the applet.


To verify the installation, go to a practice room and open a problem. Verify
that examples are expanded in the output.

Troubleshooting the installation
-------------------------------------
The most common installation problem is a JVM version mismatch. If you are
running The Arena from the browser, go to Java Plugin configuration in the
Control Panel, and verify that your default JRE is 1.4. If you are running The
Arena in WebStart, go to "File/Preferences, Java" in the WebStart application,
and verify that 1.4 is the default JRE version.

Happy coding!
kyky

