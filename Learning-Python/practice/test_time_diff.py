from datetime import datetime, date

insp_flag = True
InspStartTime = datetime(2021,8,19,15,0)
InspEndTime = datetime(2021,8,19,18,30)

def checkInspTime(insp_flag, InspStartTime ,InspEndTime):
    duringTime = InspEndTime - InspStartTime
    # print(duringTime)  # 3:30:00
    now = datetime.now()

    if insp_flag == False:
        return False
    elif now - duringTime >= InspStartTime:
        print("It is not Inspection Time")
        return False
    else:
        print("It is Inspection Time")
        return True
    

print(checkInspTime(insp_flag, InspStartTime, InspEndTime))