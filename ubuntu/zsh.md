# 插件
- encode64
encode64 是一个 Base64 编码的插件，可以让大家很方便的调试编码过程，使用也很简单：

>$ encode64 some_string
=> c29tZV9zdHJpbmc=
- urltools
同样的，urltools 还提供了 URL 编码的机制，我们可以使用 urlencode 命令对 url 进行编码：

>urlencode http://google.com
http%3A%2F%2Fgoogle.com
还对应了一个 urldecode 命令来对 url 进行解码。

urldecode http%3A%2F%2Fgoogle.com
http://google.com

- wd
>wd 插件是我比较喜欢的一个，它的作用就是能够快速的切换到常用的目录。我们用命令行时经常会遇到这样一种情况，我们常用的目录就那么几个，而这些目录有时候会再很深的层级中。使用 cd 命令在这些深层级目录中切换就比较耗费时间了。

>wd 插件正是为了解决这个问题，比如我们有一个常用的目录 /usr/nginx/www/html，我们首先进入到这个目录中，然后输入

>wd add web
这个命令相当于给当前目录做了一个标识，标识名叫做  web ，我们下次如果再想进入这个目录，只需输入：

>wd web
这样就可以完成目录切换了，非常方便。

它的原理并不复杂，它维护了一个标识和实际路径的映射表，我们使用 wd add 命令可以添加新的映射，可以使用 wd rm 命令删除已有的映射，还可以使用 wd show 命令查看现有的映射。

这个简单的插件解决了一个很实际的问题，推荐使用。 wd 插件的更多内容可以查看它的 github 主页：  https://github.com/mfaerevaag/wd

# autojump
## 安装
> sudo apt-get install autojump
> git clone https://github.com/joelthelion/autojump.git
> cd ~/autojump
> python ./install.py

>vim ~/.zshrc
添加到末尾：[[ -s ~/.autojump/etc/profile.d/autojump.sh ]] && . ~/.autojump/etc/profile.d/autojump.sh
source  .zshrc


- 添加目录记录
> j   -a   dir

- 追加当前权重
> j   -i   权重

- 减少权重
> j   -d   权重

- 显示所有目录数据
> j    -s
