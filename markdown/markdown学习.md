[TOC]
#1、atom编辑器安装
atom编辑器:下载链接 https://atom.io/
#2、插件
有用的插件推荐文章 http://www.cnblogs.com/libin-1/p/6638165.html

#3、语法学习网站
http://blog.leanote.com/post/freewalk/Markdown-%E8%AF%AD%E6%B3%95%E6%89%8B%E5%86%8C#title

----

## 列表
- shen
- de
- huan

1. shen
3. de
2. huan

## Todo list

- [x] bbs 维护
- [ ] Desktop 发布新版
    - [x] Markdown编辑器添加Todo list
    - [x] 修复白屏问题
    - [ ] 修复issue3
- [ ] Leanote 维护
    - [ ] 修复issue4


## 引用
普通引用

> 引用文本前使用 [大于号+空格]
> 折行可以不加，新起一行都要加上哦

引用里嵌套引用

> 最外层引用
> > 多一个 > 嵌套一层引用
> > > 可以嵌套很多层

引用里嵌套列表

> - 这是引用里嵌套的一个列表
> - 还可以有子列表
>     * 子列表需要从 - 之后延后四个空格开始

引用里嵌套代码块

>     同样的，在前面加四个空格形成代码块
>  
> ```
> 或者使用 ``` 形成代码块
> ```


## 换行

如果另起一行，只需在当前行结尾加 2 个空格

在当前行的结尾加 2 个空格  
这行就会新起一行

## 分隔符

如果你有写分割线的习惯，可以新起一行输入三个减号-。当前后都有段落时，请空出一行：

前面的段落

---

后面的段落

## 高级技巧

- 键位显示
使用 <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Del</kbd> 重启电脑

- 代码块

使用 <pre>void show()</pre> 元素同样可以形成代码块

- 粗斜体

<b> Markdown 在此处同样适用，如 *加粗* </b>

- 扩展

支持 jsfiddle、gist、runjs、优酷视频，直接填写 url，在其之后会自动添加预览点击会展开相关内容。

http://{url_of_the_fiddle}/embedded/[{tabs}/[{style}]]/
https://gist.github.com/{gist_id}
http://runjs.cn/detail/{id}
http://v.youku.com/v_show/id_{video_id}.html

- 公式

当你需要在编辑器中插入数学公式时，可以使用两个美元符 $$ 包裹 TeX 或 LaTeX 格式的数学公式来实现。提交后，问答和文章页会根据需要加载 Mathjax 对数学公式进行渲染。如：

$$ x = {-b \pm \sqrt{b^2-4ac} \over 2a}. $$

$$
x \href{why-equal.html}{=} y^2 + 1
$$

## 表格
- 简单方式写表格

学号|姓名|分数
-|-|-
小明|男|75
小红|女|79
小陆|男|92

- 原生方式写表格：

|学号|姓名|分数|
|-|-|-|
|小明|男|75|
|小红|女|79|
|小陆|男|92|

产品|价格
-|-:
Leanote 高级账号|60元/年
Leanote 超级账号|120元/年

- 代码显示
`sdsdsd`
