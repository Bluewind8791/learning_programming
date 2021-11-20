import time, win32con, win32api, win32gui

# # 카톡창 이름 (열려있는 상태, 최소화X, 창뒤에 숨어있는 비활성화 상태 가능)
kakao_opentalk_name = '방탕한 게임방'

def kakao_sendtext(text):
    win32api.SendMessage(hwndEdit, win32con.WM_SETTEXT, 0, text)
    SendReturn(hwndEdit)

# # Enter
def SendReturn(hwnd):
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
    time.sleep(0.01)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)

# # Handle
hwndMain = win32gui.FindWindow( None, kakao_opentalk_name)
hwndEdit = win32gui.FindWindowEx( hwndMain, None, "RichEdit50W", None)
hwndListControl = win32gui.FindWindowEx( hwndMain, None, "EVA_VH_ListControl_Dblclk", None)

# # 채팅 전송
text = "kakaotalk pc version bot test message"
kakao_sendtext(text)
