import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLineEdit, QPushButton, QLabel


class QtGUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.sb = self.statusBar()
        self.setStatusBar(self.sb)
        self.sb.showMessage("준비중")
        self.setWindowTitle("Appia")
        self.label = QLabel("counting", self)
        self.label.move(20, 20)
        self.pb = QPushButton("Start", self)
        self.pb.clicked.connect(self.count_number)
        self.pb.move(70, 20)
        self.resize(300, 300)
        self.show()

    def count_number(self):
        self.sb.showMessage("working")
        self.sb.repaint()
        for i in range(1, 10000):
            print(i)
            self.label.setText(str(i))
            self.label.repaint()
        self.sb.showMessage("Work Finished")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    ex = QtGUI()
    app.exec_()
