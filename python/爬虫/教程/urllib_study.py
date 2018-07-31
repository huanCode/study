#============================1.简单html获取=================================================
import urllib.request
response = urllib.request.urlopen('https://python.org')
print(response.read().decode('utf-8'))	#显示抓取到html内容
# print(response.status)			#显示状态，比如200、404
# print(response.getheaders())	#显示header内容
# print(response.getheader('Server'))	#显示header里某个field的值



#============================2.向服务器提交参数=================================================
# import urllib.parse
# import urllib.request

# data = bytes(urllib.parse.urlencode({'word':'hello'}),encoding='utf8')
# response = urllib.request.urlopen('http://httpbin.org/post',data=data)
# print(response.read())


#============================3.设置超时参数=================================================
# import urllib.request
# import socket
# import urllib.error

# try:
# 	response = urllib.request.urlopen('http://httpbin.org/get',timeout=0.1)
# 	print(response.read())
# except urllib.error.URLError as e:
# 	if isinstance(e.reason,socket.timeout):
# 		print('time out')

#如果未响应时间超过了timeout,则会报异常


#============================4.利用request设置=================================================










#--------------------------分析 Robots 协议------------------------------------------------
# from urllib.robotparser import RobotFileParser
# from urllib.request import urlopen

# urlStr = 'http://www.jianshu.com/robots.txt'

# rp = RobotFileParser()
# rp.set_url(urlStr)
# rp.read()	#读取robots.txt文件进行分析
# print(rp.can_fetch('*','http://www.jianshu.com'))	
#判断该url是否可以被抓取
#第一个参数是user-agent,
#第二个参数是要抓取的url
#用来判断该url是否能被user-agent抓取


# print(rp.can_fetch('*','http://www.jianshu.com/search?q=')



