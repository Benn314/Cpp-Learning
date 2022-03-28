# CLion安装及配置

1. 到官网下载CLion安装包 [官网下载](https://www.jetbrains.com/zh-cn/clion/download/#section=windows)

2. 由于我已经完成下载了，这里就不加演示了，安装的指引可以全选或者你跟我一样不想要有桌面图标，可以取消勾选`desktop icon`，绑定的后缀文件名选前4个也是ok的
3. 如果你没有下载MinGW，需要先下载它，这是C/C++的跨平台编译工具，没有它代码运行不了（可以搜索一下具体的安装教程，以免纰漏），最主要还是绑定环境变量路径，其他问题不大，下载路径直接放到D盘就好了，待会我们会用到
4. 看到网上很多教程都是说先安装插件`中文语言包`（Chinese（Simplified）Language）,但我在这一步的时候不知道为什么安装不了语言包，如果你也遇到跟我一样的情况，那么请你照我的做法一步一步就ok了

![image-20220328102807630](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220328102807630.png)



5. 打开setting（设置），找到我们要的`工具链`并打开它，工具集选择我们MinGW的路径，下方的编译器会自动给我们选择，点击应用并确定就行了

![image-20220328103145096](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220328103145096.png)



6. 遇到的一个情况：在导入项目时，GBK和UTF-8不兼容，导致出现中文乱码的问题

先看方法一：

打开setting（设置），来到文件编码（file encoding），把箭头指向的三处编码改为UTF-8，应用并确认

![image-20220328104115231](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220328104115231.png)

并且来到我们窗口页面，把下方的UTF-8改成GBK编码，点击convert转换

![image-20220328110718488](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220328110718488.png)

这样我们就解决中文乱码问题了，以后有项目导入的话，还是出现乱码问题，IDE会给出提示，点击重新加载成GBK编码格式就行了



**但是**

Clion 默认全局编码方式为 UTF-8，会导致中文乱码，所以方法一是治标不治本的，这样以后把项目导入到其他地方时，可能会出现全部问号的中文，然后你就可能被老板炒鱿鱼了



### **输出乱码解决方案**

JetBrains 提供了官方解决方案，如果是使用 MinGW，先按图所示操作，把编码方式改为 GBK，VSCode 在使用 MinGW 时，也需要在配置文件中设置编码方式为 GBK，才能正常显示中文。

![image-20220328113348966](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220328113348966.png)

三个选择框设置为**系统默认：GBK** 即可。

然后使用快捷键：`shift+ctrl+alt+/` 然后选择第一个选项 `Registry`（注册表），找到蓝色的 `run.processes.with.pty` 将其 Value 的复选框去掉，即可正常显示中文。

![image-20220328113440615](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220328113440615.png)



这样设置之后，调试台输出台中文无法显示的情况就可以被解决了。




看到网上的文章说这种方法每次重启CLion时都需要重新设置一下，但我自己试了一下，并不用重新取消勾选，不知道你们如何。

附上网上所说的一劳永逸的方法：修改配置文件

```c++
打开C:\Program Files\JetBrains\CLion 2022.3.4\bin\idea.properties
文件，将run.processes.with.pty设置为false即可。

有时候这样修改后输出会出现乱码，把右下角重新设为utf-8，
然后Convert即可。这时输入完成后，enter下一行，
再输入ctrl+D即可输入EOF。

**注意：**

**输入Ctrl+D一定要在输入完成后enter下一行后在行首输入Ctrl+D，
否则会造成某些输出中断，输出不完整！！！**
```
---

### 小结

- 文件导入为乱码，以GBK编码重新加载即可
- 控制台输出乱码，跳到输出乱码**解决方案**进行查看
- 网上很多教学都是只教操作不教原理，但每次我遇到问题都想找到遇到问题的解决方法原理是什么，为什么这么解决，有没有其他更好的解决方法，可惜~
- 希望有大佬评论区告诉下`run.processes.with.pty`的用处和为什么取消勾选，感谢！！

