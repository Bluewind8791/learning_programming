import time, win32con, win32api, win32gui
import logging
from tkinter import *
from apscheduler.schedulers.background import BackgroundScheduler
import tkinter.scrolledtext as ScrolledText


class KaTalkBot():

    # # 카톡창 이름, (활성화 상태의 열려있는 창)
    kakaoTalkRoom_friends = '방탕한 게임방'
    kakaoTalkRoom_kingdom = '하이에나 킹덤방'

    # # 채팅방에 메시지 전송
    def kakao_sendtext(chatroom_name, text):
        # # 핸들 _ 채팅방
        hwndMain = win32gui.FindWindow( None, chatroom_name)
        hwndEdit = win32gui.FindWindowEx( hwndMain, None, "RichEdit50W", None)

        win32api.SendMessage(hwndEdit, win32con.WM_SETTEXT, 0, text)
        KaTalkBot.SendReturn(hwndEdit)

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
        KaTalkBot.SendReturn(hwndkakao_edit3)
        time.sleep(1)

    def fieldBossAlert():
        text = "🚨 필보 두둥등장 5분 전 🚨"
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_friends)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_friends, text)  # 메시지 전송
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_kingdom)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_kingdom, text)  # 메시지 전송

    def fieldBossAlert_10sec():
        text = "🚨 필보 두등등장 10초 전 🚨\n첫타를 노리실려면 패시브 스킬을 사용하세요!"
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_friends)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_friends, text)  # 메시지 전송
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_kingdom)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_kingdom, text)  # 메시지 전송

    def chimGongAlert():
        text = "🚨 마인침공 입장 마감 5분 전 🚨"
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_friends)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_friends, text)  # 메시지 전송
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_kingdom)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_kingdom, text)  # 메시지 전송

    def Yimazen():
        text = "🚨 이마젠 탐험이 리셋 되었어요! 🚨"
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_friends)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_friends, text)  # 메시지 전송
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_kingdom)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_kingdom, text)  # 메시지 전송

    def worldBossAlert():
        text = "🚨 월보 두등등장! 🚨"
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_friends)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_friends, text)  # 메시지 전송
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_kingdom)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_kingdom, text)  # 메시지 전송

    def alertTest():
        text = "gui test"
        KaTalkBot.open_chatroom(KaTalkBot.kakaoTalkRoom_friends)  # 채팅방 열기
        KaTalkBot.kakao_sendtext(KaTalkBot.kakaoTalkRoom_friends, text)  # 메시지 전송




class Schduler:

    sched = None

    def startScheduler():
        Schduler.sched = BackgroundScheduler()

        # 필보 5분전 알림
        Schduler.sched.add_job(KaTalkBot.fieldBossAlert, 'cron', hour='11,17,23', minute='55', second='1', id="alert1")
        # 첫 필보 10초 전 알림
        Schduler.sched.add_job(KaTalkBot.fieldBossAlert_10sec, 'cron', hour='11,17,23', minute='59', second='50', id="alert2")
        # 침공 5분전 알림
        Schduler.sched.add_job(KaTalkBot.chimGongAlert, 'cron', hour='18', minute='5', second='1', id="test2")
        # 이마젠 탐험 리셋 알림
        Schduler.sched.add_job(KaTalkBot.Yimazen, 'cron', hour='22', minute='0', second='1', id="test3")
        # 월드보스 알림
        Schduler.sched.add_job(KaTalkBot.worldBossAlert, 'cron', hour='11,23', minute='30', second='1', id="alert3")
        # # gui test
        # sched.add_job(alertTest, 'cron', hour='9', minute='33', second='1', id="test10")

        Schduler.sched.start()

        # if Schduler.sched.running():
        statuslbl.configure(text="Scheduler is running...")

    def shutScheduler():
        # if Schduler.sched.running():
        statuslbl.configure(text="Scheduler is shutting down...")
        Schduler.sched.shutdown(wait=False)
        # else:
            # statuslbl.configure(text="Cannot shutdown scheduler because scheduler is not running at the moment.")

#########################################################################################################

def worker():
    # Skeleton worker function, runs in separate thread (see below)   
    while True:
        # Report time / date at 2-second intervals
        time.sleep(2)
        timeStr = time.asctime()
        msg = 'Current time: ' + timeStr
        logging.info(msg) 


#########################################################################################################

logging.basicConfig()
logging.getLogger('Scheduler','KatalkBot').setLevel(logging.DEBUG)


window = Tk()
window.title("제2의 나라 스케쥴 알리미") # window title
window.geometry("320x200") # window size

lbl = Label(window, text="제2의 나라 스케쥴 알리미입니다.")
lbl.grid(column=1, row=1) # give it the location
# window.resizeable(False, False) # resizeable

startSchBtn = Button(window, padx=10, text="Start Scheduler", command=Schduler.startScheduler) # start scheduler button
startSchBtn.grid(column=1, row=2, sticky=N+W+S)

shutSchBtn = Button(window, padx=10, text="Shutdown Scheduler", command=Schduler.shutScheduler) # shutdown scheduler button
shutSchBtn.grid(column=1, row=3, sticky=N+W+S)

statuslbl = Label(window, text="")
statuslbl.grid(column=1, row=4, sticky=N+W+S)


debugFrame = Frame(window)
debugFrame.pack()
scrollbar = Scrollbar(debugFrame)
scrollbar.pack(side="right", fill="y") # right side scroll bar position

# debugBox = 

# 체크 박스
# chkBox = Checkbutton(window, text="필보 5분 전 알림", variable=fieldbossfunction)
# chkBox.select() # 자동으로 선택 처리
# chkBox.pack()
# if fieldbossfunction.get() # ture false 값 얻을 수 있음

window.mainloop()
