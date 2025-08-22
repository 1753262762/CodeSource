from wxauto import WeChat # type: ignore
import requests # type: ignore
import pyautogui # type: ignore
wx=WeChat()

listen_list=['elma']

while True:
    msgs=wx.GetAllNewMessage()
    if len(msgs) != 0:
        if listen_list[0] in str(msgs[listen_list[0]]):
            for msg in msgs[listen_list[0]]:
                print(f'{listen_list[0]}:{str(msg)}')
                url=f'http://api.qingyunke.com/api.php?key=free&appid=0&msg={msg}'
                content=requests.get(url).json()['content'].replace('<br>','')
                wx.SendMsg(content,listen_list[0])
        else :
            for msg in msgs[listen_list[0]]:
                print('我:'+str(msg))
                pyautogui.click(600,300)
