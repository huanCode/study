#============================1.简单===========================================
# from lxml import etree

# text = '''
# <div>
# <li class="item-0"><a href="link1.html">first</a></li>
# <li class="item-1"><a href="link2.html">secode</a></li>
# </div>
# '''

# html = etree.HTML(text)
# result = etree.tostring(html)
# print(result.decode('utf-8'))

#打印结果如下
# <html>
# 	<body>
# 		<div>
# 			<li class="item-0"><a href="link1.html">first</a></li>
# 			<li class="item-1"><a href="link2.html">secode</a></li>
# 		</div>
# 	</body>
# </html>



#============================2.简单===========================================
from lxml import etree
text = '''
<div>
<li class="item-0 item_first"><a href="link1.html">first</a></li>
<li class="item-1" name="sdh"><a href="link2.html">secode</a></li>
<li class="item-2"><a href="link3.html">third</a></li>
<li class="item-3"><a href="link4.html">four</a></li>
</div>
'''

html = etree.HTML(text)

# 获取所有的节点
result = html.xpath('//*')

print(result)

# 只获取li节点
result = html.xpath('//li')
print('1===============================')
print(result)

# 只获取li的直接子节点a
result = html.xpath('//li/a')
print('2===============================')
print(result)

# 获取节点a的父父节点div
result = html.xpath('//a[@href="link1.html"]/../..')
print('3===============================')
print(result)

# 根据属性查找
result = html.xpath('//li[@class="item-0"]')
print('4===============================')
print(result)

# 获取节点的文本
result = html.xpath('//li[@class="item-0"]//text()')
print('4===============================')
print(result)

# 获取节点的属性值
result = html.xpath('//li/a/@href')
print('5===============================')
print(result)

# 指定属性的多值去匹配
result = html.xpath('//li[contains(@class,"first")]/a/text()')
print('6===============================')
print(result)


# 多个属性匹配
result = html.xpath('//li[contains(@class,"item") and @name="sdh" ]/a/text()')
print('7===============================')
print(result)


#按序匹配
print('7===============================')
result = html.xpath('//li[3]/a/text()')		#选取第3个li
print(result)
result = html.xpath('//li[last()]/a/text()')		#选取最后个li
print(result)
result = html.xpath('//li[position()<3]/a/text()')		#选取前2个li
print(result)