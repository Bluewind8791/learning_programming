
import wmi

c = wmi.WMI()
def check_process_running(str_):
    if(c.Win32_Process(name=str_))
        print("Process is running")
    else:
        print("Process is not running")


