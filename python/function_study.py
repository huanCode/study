#=============================1.def用法【函数多态性】========================================
# if 0:
# 	def show():
# 		print('show 1')
# else:
# 	def show():
# 		print('show 2')

# show()

#作用：
#def是在程序执行时，当做普通语句执行的，不需要单独的编译时间，从上面if的不同选择，可以执行同个show函数的不同实现，
#因此认为不同选择时，show的不同实现绑定到唯一show名字，这个就和多态有点类似

#=============================2.def用法【函数实现多态性】========================================

# def times(x,y):
# 	return x * y

# print(times(2,3))
# print(times('sdh',3))

#说明：
#从上面的同个函数实现，确实现了不同功能，这是因为python不需要定义变量、参数的类型，于是*操作符可以根据不同的类型，实现不同操作
#因此从这也可以知道，多态性在python中更加灵活多变


#===============================3.变量的作用域 =============================================
# x =3
# def test_0():
# 	return x * 2

# def test_1():
# 	x = 1
# 	return x * 2

# print(test_0())
# print(test_1())

#知识点：
#1.从两个test函数的结果可以知道，函数里的变量搜索是先从函数作用域开始，没找到再到函数外面搜索
#2.函数的变量和函数外的变量名一样时，优先使用函数内的变量
#3.变量作用域可以分为local、global、__builtin__三种，其中local对应函数、global对应当前文件里、


#===============================4.函数要修改函数外变量方法 =============================================
# x = 4
# def fun_0():

# 	global x
# 	x = 3
# 	return x * 2


# print(fun_0())
# print(x)

#知识点：
#1.当函数要修改外面的变量x时，需要global声明，不把对x的赋值当做定义一个新的local变量


#===============================5.嵌套函数的特殊变量的作用域 =============================================

# def f1():
# 	x = 88
# 	def f2():
# 		print(x)

# 	return f2

# action = f1()
# action()


#=================================6.工厂函数 ======================================



#=================================7.避免修改函数的参数===========================


def changer(a):
	# a = a[:]
	a[0] = 'sdh'
	print(a)

L = [1,2]
changer(L[:])		#内部还是可以被改
# changer(tuple(L))	#根本禁止被改
print(L)

#知识点：
#像字典、列表等，通过参数传递给函数内时，是可以被修改的，上面方法避免了被修改,里面其实是copy

print(dir())