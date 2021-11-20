import sys
from PyQt5 import QtWidgets, QtGui
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import *
from PyQt5.QtCore import QCoreApplication, Qt, QLine
from os import environ


def suppress_qt_warnings():
    environ["QT_DEVICE_PIXEL_RATIO"] = "0"
    environ["QT_AUTO_SCREEN_SCALE_FACTOR"] = "1"
    environ["QT_SCREEN_SCALE_FACTORS"] = "1"
    environ["QT_SCALE_FACTOR"] = "1"


class MyApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def pushBtnFunction(self):
        self.statusBar().showMessage("Scheduler is running...")
        self.statusBar().repaint()
        # print("Button Pushed")


    def initUI(self):
        self.setWindowTitle("제2의나라 스케쥴 알리미")
        self.setWindowIcon(QIcon("icon.jpeg"))
        self.setGeometry(300, 300, 300, 200)  # x, y, width, height

        self.lbl1 = QLabel("제2의나라 스케쥴 알리미입니다.")
        self.lbl2 = QLabel("점검 시간을 설정해 주세요.")

        # - 점검 시간 선택 창 -

        # - On Off Button -
        onBtn = QPushButton("powerOn.png")
        offBtn = QPushButton("powerOff.png")

        # - layout -
        hbox_lbl = QHBoxLayout()
        hbox_lbl.addStretch(1)
        hbox_lbl.addWidget(self.lbl1)
        hbox_lbl.addWidget(self.lbl2)
        hbox_lbl.addStretch(1)

        hbox_button = QHBoxLayout()
        hbox_button.addStretch(1)
        hbox_button.addWidget(onBtn)
        hbox_button.addWidget(offBtn)
        hbox_button.addStretch(1)

        vbox = QVBoxLayout()
        vbox.addStretch(1)
        vbox.addLayout(hbox_lbl)
        vbox.addLayout(hbox_button)
        vbox.addStretch(1)

        self.setLayout(vbox)

        # - Exit Action -
        exitAction = QAction(QIcon("powerOff.png"), "Exit", self)
        exitAction.setShortcut("Ctrl+Q")
        exitAction.triggered.connect(qApp.quit)

        # - Start Action -
        startAction = QAction(QIcon("powerOn.png"), "Start", self)
        startAction.setShortcut("Ctrl+S")
        startAction.triggered.connect(self.pushBtnFunction)

        # - Tool Bar -
        # self.tb = self.addToolBar("ToolBar")
        # self.tb.addAction(startAction)
        # self.tb.addAction(exitAction)

        # - Status Bar Setting -
        self.statusBar().showMessage("Scheduler is ready...")

        self.show()  # 위젯을 스크린에 표시



if __name__ == "__main__":
    suppress_qt_warnings()
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())
