#================================ 1.对象和类的成员变量的区别 ===========================
# class Test:
# 	num = 1
# 	def __init__(self,parm):	#构造函数
# 		print('init')
# 		self.num = parm

# 	def get_0(self):
# 		self.x = 2
# 		# return self.x

# 	def get_1(self):
# 		self.y = 3

# t = Test(4)
# t.get_0()

# y = Test(5)
# y.get_1()

# print(t.x)
# print(y.y)

# print(t.__dict__.keys())	#查看该对象拥有的成员变量，不包括继承而来的
# print(t.__class__)		#查看对象的类对象
# print(y.num)

#调用下面两个会报错,因为对象还没拥有该成员变量
# print(t.y)
# print(y.x)


#知识点:
#在java和c++中,只要声明了成员变量,该类的所有对象便拥有了相同的成员变量,但是python不是这样的，
#因为python是在运行时编译的,而java、c++是先编译好才能运行;于是python更加有灵活多变的,就是同个类的不同对象可以拥有自己独立的成员变量,
#只要在运行时对成员变量赋值,该对象就拥有该成员变量;

##================================ 2.类对象动态添加方法 ===========================
# class Test:
# 	name = 'sdh'


# def show_name(self):
# 	print(self.name)

# Test.show = show_name

# t = Test()

# Test.show(t)
# t.show()
# t.name = 'huan'
# print(t.name)

# Test.name ='de'	#这种修改只对新创建的对象有影响
# print(t.name)

# a = Test()
# print(a.name)

#下面这样是会报错
# t.show_1 = show_name		
# t.show_1()

#==========================3.调用父类的init======================================
class Father:
	def __init__(self):
		print('Father')

class son(Father):
	def __init__(self):
		Father.__init__(self)
		print('son')

a = son()