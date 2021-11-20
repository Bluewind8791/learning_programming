import time, win32con, win32api, win32gui
from tkinter import *
from tkinter.ttk import *
from apscheduler.schedulers.background import BackgroundScheduler
from datetime import datetime

# - 카톡창 이름 (활성화 상태의 열려있는 창) -
kakaoTalkRoom_friends = "방탕한 게임방"
kakaoTalkRoom_kingdom = "하이에나 킹덤방"

# - 채팅방에 메시지 전송 -
def kakao_sendtext(chatroom_name, text):
    # 핸들 _ 채팅방
    hwndMain = win32gui.FindWindow(None, chatroom_name)
    hwndEdit = win32gui.FindWindowEx(hwndMain, None, "RichEdit50W", None)

    win32api.SendMessage(hwndEdit, win32con.WM_SETTEXT, 0, text)
    SendReturn(hwndEdit)


# - 엔터 -
def SendReturn(hwnd):
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
    time.sleep(0.01)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)


# - 채팅방 열기 -
def open_chatroom(chatroom_name):
    # # # 채팅방 목록 검색하는 Edit (채팅방이 열려있지 않아도 전송 가능하기 위하여)
    hwndkakao = win32gui.FindWindow(None, "카카오톡")
    hwndkakao_edit1 = win32gui.FindWindowEx(hwndkakao, None, "EVA_ChildWindow", None)
    hwndkakao_edit2_1 = win32gui.FindWindowEx(hwndkakao_edit1, None, "EVA_Window", None)
    hwndkakao_edit2_2 = win32gui.FindWindowEx(hwndkakao_edit1, hwndkakao_edit2_1, "EVA_Window", None)
    hwndkakao_edit3 = win32gui.FindWindowEx(hwndkakao_edit2_2, None, "Edit", None)

    # - Edit에 검색 _ 입력되어있는 텍스트가 있어도 덮어쓰기됨
    win32api.SendMessage(hwndkakao_edit3, win32con.WM_SETTEXT, 0, chatroom_name)
    time.sleep(1)  # 안정성 위해 필요
    SendReturn(hwndkakao_edit3)
    time.sleep(1)


# - 점검 시간인지 체크 -
def checkInspTime(InspStartTime, InspEndTime):
    duringTime = InspEndTime - InspStartTime
    # print(duringTime)  # 3:30:00
    now = datetime.now()

    if now - duringTime >= InspStartTime:
        print("It is not Inspection Time")
        return False
    else:
        print("It is Inspection Time")
        return True


def fieldBossAlarm_10min():
    text = "🚨 필드보스 등장 10분 전 🚨"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송


def fieldBossAlarm_3min():
    text = "🚨 필드보스 등장 3분 전 🚨"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def fieldBossAlarm_10sec():
    text = "🚨 필드보스 등장 약 10초 전 🚨\n   첫타를 노려보세요!"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def kaFieldBossAlarm():
    text = "🚨 카오스 필드보스 등장 5분 전 🚨"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def YimazenAlarm():
    text = "🚨 이마젠 탐험 월드 리셋 알림 🚨"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def worldBossAlarm():
    text = "🚨 월드보스 뚜둥등장! 🚨"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def predictionAlarm():
    text = "🚨 유물 전장 승부예측이 시작되었습니다! 🚨"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def predictionEndAlarm():
    text = "🚨 유물 전장 승부예측 🚨\n   마감까지 10분 남았습니다!"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def InpectionEndAlarm():
    text = "🚨 업데이트 점검이 끝났을지도? 🚨\n   자세한 사항은 https://forum.netmarble.com/enn_ko/list/3/1"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송
    time.sleep(0.1)
    open_chatroom(kakaoTalkRoom_kingdom)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_kingdom, text)  # 메시지 전송


def alarmTest():
    text = "bot test"
    open_chatroom(kakaoTalkRoom_friends)  # 채팅방 열기
    kakao_sendtext(kakaoTalkRoom_friends, text)  # 메시지 전송


class Schduler:

    sched = None

    def startScheduler():
        Schduler.sched = BackgroundScheduler()
        if checkInspTime(InspStartTime, InspEndTime):
            # - Boss Alarm -
            # 필보 10분 전 알림 (11시, 17시, 23시 57분)
            Schduler.sched.add_job(fieldBossAlarm_10min, "cron", hour="11,17,23", minute="50", second="1", id="boss1")
            # 필보 첫타용 10초 전 알림
            Schduler.sched.add_job(fieldBossAlarm_10sec, "cron", hour="11,17,23", minute="59", second="45", id="boss2")
            # 필보 3분 전 알림
            Schduler.sched.add_job(fieldBossAlarm_3min, "cron", hour="11,17,23", minute="57", second="2", id="boss5")
            # "카오스 필보" 5분 전 알림
            Schduler.sched.add_job(kaFieldBossAlarm, "cron", hour="12,18,00", minute="25", second="1", id="boss3")
            # 월드보스 알림 (11시30분, 17:30, 23시 30분)
            Schduler.sched.add_job(worldBossAlarm, "cron", hour="11,17,23", minute="30", second="1", id="boss4")

            # 이마젠 탐험 리셋 알림 (오후 10시, 22)
            Schduler.sched.add_job(YimazenAlarm, "cron", hour="10,16,22", minute="0", second="1", id="alarm1")
            # 유물 전장 승부예측 금 21:30 ~ 토 21:30 입니다
            Schduler.sched.add_job(
                predictionAlarm, "cron", day_of_week="fri", hour="21", minute="30", second="1", id="alarm2"
            )
            Schduler.sched.add_job(
                predictionEndAlarm, "cron", day_of_week="sat", hour="21", minute="20", second="1", id="alarm2_1"
            )

            # - Event -

            # - 점검 끝 알림 -
            Schduler.sched.add_job(
                InpectionEndAlarm,
                "cron",
                year=InspEndTime.year,
                month=InspEndTime.month,
                day=InspEndTime.day,
                hour=InspEndTime.hour,
                minute=InspEndTime.minute,
                second="1",
                id="inpection",
            )

            Schduler.sched.start()
            statuslbl.configure(text="Scheduler is running...")
            print("Scheduler start running...")

    def shutScheduler():
        statuslbl.configure(text="Scheduler is shutting down...")
        Schduler.sched.shutdown(wait=False)


# year (int|str) – 4-digit year
# month (int|str) – month (1-12)
# day (int|str) – day of month (1-31)
# week (int|str) – ISO week (1-53)
# day_of_week (int|str) – number or name of weekday (0-6 or mon,tue,wed,thu,fri,sat,sun)
# hour (int|str) – hour (0-23)
# minute (int|str) – minute (0-59)
# second (int|str) – second (0-59)


##############################################################################################################

# - 점검 시간 변수 설정 -
InspStartTime = datetime(2021, 8, 19, 15, 0)
InspEndTime = datetime(2021, 8, 19, 19, 30)


window = Tk()
window.title("제2의 나라 스케쥴 알리미")  # window title
# window.geometry("320x200") # window size

lbl = Label(window, text="제2의 나라 스케쥴 알리미입니다.")
lbl.grid(column=1, row=1)  # give it the location
# window.resizeable(False, False) # resizeable

select_lbl = Label(window, text="점검 시작시간을 입력해 주세요.")
select_lbl.grid(column=1, row=2)

select_Insp_year = Combobox(window, values=[2011, 2022])
print(dict(select_Insp_year))
select_Insp_year.grid(column=1, row=3)
select_Insp_year.current(1)

startSchBtn = Button(window, padx=10, text="Start Scheduler", command=Schduler.startScheduler)  # start scheduler button
startSchBtn.grid(column=1, row=4)

shutSchBtn = Button(
    window, padx=10, text="Shutdown Scheduler", command=Schduler.shutScheduler
)  # shutdown scheduler button
shutSchBtn.grid(column=1, row=7)

# - Status Label -
statuslbl = Label(window, text="")
statuslbl.grid(column=1, row=9)

window.mainloop()
