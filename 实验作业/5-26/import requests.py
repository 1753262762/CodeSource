import requests
import re
from openpyxl import Workbook
import os

def clean_filename(s):
    """清洗文件名,去除非法字符"""
    return re.sub(r'[\/:*?"<>|]', '_', s)

def main():
    url = 'https://www.ruiwen.com/huayu/8418076.html'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    
    try:
        response = requests.get(url, headers=headers, timeout=10)
        response.raise_for_status()
        html = response.text
    except Exception as e:
        print(f'错误:获取网页失败 - {e}')
        return
    title_pattern = re.compile(r'<title>(.*?)</title>', re.S)
    title_match = title_pattern.search(html)
    title = title_match.group(1).strip() if title_match else 'UnknownTitle'
    valid_title = clean_filename(title)
    content_pattern = re.compile(r'<div class="content">([\s\S]*?)</div>', re.S)
    content_match = content_pattern.search(html)
    content_text = []
    
    if content_match:
        content_html = content_match.group(1)
        p_pattern = re.compile(r'<p>(.*?)</p>', re.S)
        content_text = [p.strip() for p in p_pattern.findall(content_html) if p.strip()]
    else:
        p_pattern = re.compile(r'<p>(.*?)</p>', re.S)
        content_text = [p.strip() for p in p_pattern.findall(html) if p.strip()]
    if not content_text:
        content_text = [re.sub(r'<.*?>', '', html).strip()]
    try:
        wb = Workbook()
        ws = wb.active
        ws.title = 'Content'
        ws.append(['网页标题', title])
        ws.append([''])  
        ws.append(['内容'])
        for para in content_text:
            ws.append([para])
        for col in ws.columns:
            max_len = max(len(str(cell.value)) for cell in col) if col else 0
            ws.column_dimensions[col[0].column_letter].width = max_len + 2
        
        filename = f'{valid_title}.xlsx'
        wb.save(filename)
        print(f'成功保存到:{filename}')
    except Exception as e:
        print(f'错误:保存Excel失败 - {e}')
    finally:
        wb.close()

if __name__ == '__main__':
    main()
