import requests
from bs4 import BeautifulSoup
def getHTMLText(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()  # 检查请求状态
        r.encoding = 'utf-8'
        return r.text
    except:
        return ""
url = "http://www.baidu.com"
text=getHTMLText(url)
print(text[:500])
