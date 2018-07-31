# import requests
# r = requests.get('https://www.baidu.com/')
# print(type(r))
# print(r.status_code)	#状态码
# print(r.text)		#内存
# print(r.cookies)


#==========================2. GET附加额外信息请求 ==============================
# import requests
# data = {
# 	'name':'sdh',
# 	'age':123
# }
# r = requests.get('http://httpbin.org/get',params=data)
# print(r.text)
# print(r.json())	#解析为json的字典，如果text不是json格式，是会报错

# #get请求的额外信息方式：http://httpbin.org/get?age=123&name=sdh



#==========================3. 加入headers信息 和正则表达式筛选 ==============================
# import requests
# import re

# headers = {
# 	'User-Agent':'Mozilla/5.0 (Macintosh;Intel Mac OS X 10_11_4) AppleWebKit/537.36(KHTML,like Gecko) Chrome/52.0.2743.116 Safari/537.36'
# }
# r = requests.get('https://www.zhihu.com/explore',headers=headers)
# pattern = re.compile('explore-feed.*?question_link.*?>(.*?)</a>',re.S)	#正则表达式
# titles =re.findall(pattern,r.text)
# print(titles)


#==========================4. 抓取保存图片 ==============================
# import requests

# r = requests.get('https://github.com/favicon.ico')
# # print(r.text)
# # print(r.content)
# with open('favicon.ico','wb') as f:
# 	f.write(r.content)

# ==========================5. 上传文件 ==============================
# import requests
# files = {'file':open('favicon.ico','rb')}
# r = requests.post('http://httpbin.org/post',files=files)
# print(r.text)


# ==========================6. cookie操作 ==============================
import requests

r = requests.get('https://www.baidu.com')
print(r.cookies)
for key,value in r.cookies.items():
	print(key +'='+value)