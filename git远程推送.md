# 本地仓库同步至github远程仓库



现在是2022年3月26号 23:06，这是我第二次被git折磨得不行了，之前应该记笔记的，唉~刚刚本来想把git bash最小化不小心点成关闭了，没办法，那我就先记点自己还有印象的。

最容易应该是新建github仓库然后直接推送本地仓库，可能是我已经创建完了仓库并且上传了文件，导致本地上传时跟远程仓库有冲突文件等等，不说废话，先讲流程



首先我们要让本地仓库关联远程仓库（如果没有仓库可以新建一个，和本地仓库名最好一样，不然可能会报错）

![图一](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220326231534375.png)

<img src="C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220326231819957.png" alt="image-20220326231819957" style="zoom:67%;" />



例如，我要让本地仓库关联这个远程仓库，我们可以根据GitHub的提示，在本地的`Cpp-learning`仓库下运行命令：

```cmd
$ git remote add origin git@github.com:Benn314/Cpp-Learning.git
```

**补充一点：**

如果`$ git remote add origin git@github.com:Benn314/Cpp-Learning.git`失败，可以先看一下本地库中有没有.git文件，如果没有的话要先执行`git init`定义，一般是没有定义这个错误的。

```cmd
$ git init
```



请千万注意，把上面的`Cpp-learning`替换成你自己的GitHub账户名，否则，你在本地关联的就是我的远程库，关联没有问题，但是你以后推送是推不上去的，因为你的SSH Key公钥不在我的账户列表中。

添加后，远程库的名字就是`origin`，这是Git默认的叫法，也可以改成别的，但是`origin`这个名字一看就知道是远程库。

下一步，就可以把本地库的所有内容推送到远程库上：

```cmd
$ git push -u origin main
Counting objects: 20, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (15/15), done.
Writing objects: 100% (20/20), 1.64 KiB | 560.00 KiB/s, done.
Total 20 (delta 5), reused 0 (delta 0)
remote: Resolving deltas: 100% (5/5), done.
To github.com:michaelliao/learngit.git
 * [new branch]      master -> master
Branch 'master' set up to track remote branch 'master' from 'origin'.
```



把本地库的内容推送到远程，用`git push`命令，实际上是把当前分支`main`推送到远程。(从2020年起，master改名为main分支)

由于远程库是空的，我们第一次推送`main`分支时，加上了`-u`参数，Git不但会把本地的`main`分支内容推送的远程新的`main`分支，还会把本地的`main`分支和远程的`main`分支关联起来，在以后的推送或者拉取时就可以简化命令，推送成功的话就是图一的界面了。



从现在起，只要本地作了提交，就可以通过命令：

```cmd
$ git push origin main
```



我在git push的时候遇到了三个麻烦，其中一个是git push提示Everything up-to-date，并且文件也没有提交上去

**解决方法**：

```cmd
git add .
git commit -m "message"
git push origin main
```

另外两个我给忘了。。有error有fatal，我记得自己最后大概是这么解决的（有点傻，反正就是各种尝试）

①有说是SSH过期的或者失效的，让你重新配置生成并添加到GitHub settings里

②是直接把本地文件直接远程推送覆盖掉远程仓库的文件，当时自己也是比较心急蛤，就试了这种方法，发现成功推送了，证明我的SSH密钥没有失效

```cmd
git push -u origin main -f
```

③解绑远程库并重新关联

用`git remote rm <name>`命令，使用前，建议先用`git remote -v`查看远程库信息：

```cmd
$ git remote -v
origin  git@github.com:michaelliao/learn-git.git (fetch)
origin  git@github.com:michaelliao/learn-git.git (push)
```

然后，根据名字删除，比如删除`origin`：

```cmd
$ git remote rm origin
```

解绑后，远程库本身并没有任何改动。如果需要删除远程库，需要登录到GitHub，在后台页面找到删除按钮再删除。

接着重复上面的关联远程库命令

```cmd
git remote add origin git@server-name:path/repo-name.git
```



最后再`git push -u origin main`，然后成功出现Everything up-to-date，可以到GitHub查看该仓库是否正常上传，没有同步更新提交文件的话，就回到Everything up-to-date的**解决方法**进行`git add . `和`git commit -m "message"`等操作，将文件保存到暂存区再进行`git push origin main`上传更新操作



补充一点：

如果远程库有本地库没有的文件，我们可以先用`git pull`命令将远程库合并到本地库，再`git push origin main`进行上传



### 小结

- **找个时间快点系统地学一遍git！**

- 要关联一个远程库，使用命令`git remote add origin git@server-name:path/repo-name.git`；

- 关联一个远程库时必须给远程库指定一个名字，`origin`是默认习惯命名；

- 关联后，使用命令`git push -u origin master`第一次推送master分支的所有内容；

- 此后，每次本地提交后，只要有必要，就可以使用命令`git push origin master`推送最新修改；
  

分布式版本系统的最大好处之一是在本地工作完全不需要考虑远程库的存在，也就是有没有联网都可以正常工作，而SVN在没有联网的时候是拒绝干活的！当有网络的时候，再把本地提交推送一下就完成了同步，真是太方便了！



**参考文章**：

[添加远程库](https://www.liaoxuefeng.com/wiki/896043488029600/898732864121440)

[error: src refspec master does not match any. 错误处理办法 - JeremyLee87 - 博客园 (cnblogs.com)](https://www.cnblogs.com/jeremylee/p/5715289.html)

