import sys
from PyQt5.QtCore import QSize, Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import *


class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super().__init__()
        self.main_widget = FormWidget(self)
        self.setCentralWidget(self.main_widget)
        self.init_UI()

    def init_UI(self):
        self.statusBar().showMessage("Scheduler is ready...")

        self.setWindowTitle("제2의나라 스케쥴 알리미")
        self.setWindowIcon(QIcon("icon.jpeg"))
        self.setGeometry(300, 300, 300, 200)  # x, y, width, height
        self.show()



class FormWidget(QWidget):

    def __init__(self, parent):
        super(FormWidget, self).__init__(parent)
        self.parent = parent
        self.init_UI()

    def initUI(self):

        lbl1 = QLabel("제2의나라 스케쥴 알리미입니다.")
        lbl2 = QLabel("점검 시간을 설정해 주세요.")

        # - 점검 시간 선택 창 -

        onBtn = QPushButton("", self)
        onBtn.clicked.connect(self.changeStatBar)
        onBtn.setIcon(QIcon("powerOn.png"))
        onBtn.setIconSize(QSize(35,35))

        offBtn = QPushButton("powerOff", self)
        offBtn.setIcon(QIcon("powerOff.png"))
        onBtn.setIconSize(QSize(35,35))

        # - layout -
        hbox_lbl1 = QHBoxLayout()
        hbox_lbl1.addStretch(1)
        hbox_lbl1.addWidget(lbl1)
        hbox_lbl1.addStretch(1)

        hbox_lbl2 = QHBoxLayout()
        hbox_lbl2.addStretch(1)
        hbox_lbl2.addWidget(lbl2)
        hbox_lbl2.addStretch(1)

        hbox_button = QHBoxLayout()
        hbox_button.addStretch(1)
        hbox_button.addWidget(onBtn)
        hbox_button.addWidget(offBtn)
        hbox_button.addStretch(1)

        vbox = QVBoxLayout()
        vbox.addStretch(1)
        vbox.addLayout(hbox_lbl1)
        vbox.addStretch(1)
        vbox.addLayout(hbox_lbl2)
        vbox.addStretch(1)
        vbox.addLayout(hbox_button)
        vbox.addStretch(1)

        self.setLayout(vbox)
        
        self.setWindowTitle("제2의나라 스케쥴 알리미")
        self.setGeometry(300, 300, 300, 200)  # x, y, width, height
        self.show()

    def changeStatBar(self):
        self.parent.statusbar.showMessage("Scheduler is running...")

        # self.statusBar().showMessage("Scheduler is running...")
        # self.statusBar().repaint()



if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MainWindow()
    sys.exit(app.exec_())