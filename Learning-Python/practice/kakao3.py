#########################################
## 카카오톡pc 1~2 편 + 크롤링 + 스케줄러 ##
#########################################

import time, win32con, win32api, win32gui
from apscheduler.schedulers.background import BackgroundScheduler


# # 카톡창 이름, (활성화 상태의 열려있는 창)
kakao_opentalk_name = '방탕한 게임방'


# # 채팅방에 메시지 전송
def kakao_sendtext(chatroom_name, text):
    # # 핸들 _ 채팅방
    hwndMain = win32gui.FindWindow( None, chatroom_name)
    hwndEdit = win32gui.FindWindowEx( hwndMain, None, "RichEdit50W", None)

    win32api.SendMessage(hwndEdit, win32con.WM_SETTEXT, 0, text)
    SendReturn(hwndEdit)


# # 엔터
def SendReturn(hwnd):
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
    time.sleep(0.01)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)


# # 채팅방 열기
def open_chatroom(chatroom_name):
    # # # 채팅방 목록 검색하는 Edit (채팅방이 열려있지 않아도 전송 가능하기 위하여)
    hwndkakao = win32gui.FindWindow(None, "카카오톡")
    hwndkakao_edit1 = win32gui.FindWindowEx( hwndkakao, None, "EVA_ChildWindow", None)
    hwndkakao_edit2_1 = win32gui.FindWindowEx( hwndkakao_edit1, None, "EVA_Window", None)
    hwndkakao_edit2_2 = win32gui.FindWindowEx( hwndkakao_edit1, hwndkakao_edit2_1, "EVA_Window", None)
    hwndkakao_edit3 = win32gui.FindWindowEx( hwndkakao_edit2_2, None, "Edit", None)

    # # Edit에 검색 _ 입력되어있는 텍스트가 있어도 덮어쓰기됨
    win32api.SendMessage(hwndkakao_edit3, win32con.WM_SETTEXT, 0, chatroom_name)
    time.sleep(1)   # 안정성 위해 필요
    SendReturn(hwndkakao_edit3)
    time.sleep(1)


def field12_1():
    open_chatroom(kakao_opentalk_name)  # 채팅방 열기
    text = "🚨 필보 5분 전 🚨"
    kakao_sendtext(kakao_opentalk_name, text)  # 메시지 전송

def chimgong_mine():
    open_chatroom(kakao_opentalk_name)  # 채팅방 열기
    text = "🚨 마인침공 입장 마감 5분 전 🚨"
    kakao_sendtext(kakao_opentalk_name, text)  # 메시지 전송



def main():
    sched = BackgroundScheduler()
    # hour (0~23)
    # minute (0~59)
    # second (0-59)

    # # 매 분 11:55, 17:55, 23:55 필보 5분전 전송
    sched.add_job(field12_1, 'cron', hour='11,17,23', minute='55', second='1', id="test1")
    # # 매 분 18:05 침공 5분전 전송
    sched.add_job(chimgong_mine, 'cron', hour='18', minute='5', second='1', id="test2")

    sched.start()

    while True:
        print("실행중.................")
        print(f'{time.strftime("%H:%M:%S")}')
        time.sleep(1)


if __name__ == '__main__':
    main()