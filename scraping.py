# -*- coding: utf-8 -*-
import requests
import string
from bs4 import BeautifulSoup as bs
import sh

url = raw_input('Enter a link: ')
#print(url)
lv = raw_input('Enter a level: ')
#print(lv)

page = requests.get(url)
soup = bs(page.text, "html.parser")

title = soup.find_all('li')
problem = soup.find_all('h6')
limit = soup.find_all('h5')

titleText = title[2].text
#print(title[2].text)
#print(titleText)
#print(problem[0].text)
#print(limit[0].text)

mkdirStr = title[2].text+'('+url[58:]+')'

#print(mkdirStr)

sh.mkdir('./lv'+str(lv)+'/'+mkdirStr)

sh.touch('./lv'+str(lv)+'/'+mkdirStr+'/README.md')

sh.touch('./lv'+str(lv)+'/'+mkdirStr+'/'+url[58:]+'.cpp')

readme = open('./lv'+str(lv)+'/'+mkdirStr+'/README.md','w')

readme.write('# '+titleText.encode('utf-8')+'\n\n---\n\n')
readme.write('## 문제 설명\n\n\n\n---\n\n')
readme.write('## 제한사항\n\n\n\n---\n\n')
readme.write(str(url))

readme.close()

print('Succese')
