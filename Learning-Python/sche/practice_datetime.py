from datetime import datetime, time
import time

starttime = datetime(2021, 8, 21, 20, 30)
endtime = datetime(2021, 8, 21, 23, 50)

while(True):
  now = datetime.now()
  start2now = starttime - now
  # print(start2now.seconds)
  now2end = endtime - now
  # print(now2end.seconds)

  if starttime <= now: #점검 시작
    if endtime <= now: # 점검 끝
      print("점검 끝")
      break
    else: # 점검 중
      print("점검 중")
      print(now2end.seconds/60)
      time.sleep(5)
      # time.sleep(now2end.seconds - 1)
      continue
  else: # 점검 시작 안함
    print("점검 시작 안함")
    print(start2now.seconds/60)
    time.sleep(5)
    # time.sleep(start2now.seconds - 1)
    continue



# if 시작시간 1시 <= 현재시간 2시 = 점검 시작
#   끝시간 3시 <= 현재시간 4시 = 점검 끝
#     #break

#   else 점검 중
#     끝시간 - 현재시간 - 1초 딜레이
#     다시 확인

# else 점검 아직 시작 안함
#   현재시간 - 시작시간 - 1초 딜레이
#   다시 확인