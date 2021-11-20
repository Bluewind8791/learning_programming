import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QStatusBar, QLabel, QPushButton, QFrame
from PyQt5.QtCore import QDateTime, Qt


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.date = QDateTime.currentDateTime()

        self.statusBar().showMessage("bla-bla bla")

        self.lbl2 = QLabel("")
        self.lbl2.setStyleSheet("border: 0; color: blue;")

        self.statusBar().reformat()
        self.statusBar().setStyleSheet("border: 0; background-color: #FFF8DC;")
        self.statusBar().setStyleSheet("QStatusBar::item {border: none;}")

        self.statusBar().addPermanentWidget(self.lbl2)

        self.lbl2.setText(self.date.toString("dd.MM.yyyy, hh:mm:ss"))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
