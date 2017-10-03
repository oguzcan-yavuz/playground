#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from PyQt4.QtCore import pyqtSlot
from PyQt4.QtGui import *


class SimpleCalculator(QWidget):
    def __init__(self):
        super(SimpleCalculator, self).__init__()
        # result
        self.result = 0.0
        # QLabel for showing current result
        self.current = QLabel('0.0', self)
        # TextBox for user input
        self.textbox = QLineEdit('0.0', self)
        # Buttons
        self.btn_add = QPushButton('+', self)
        self.btn_sub = QPushButton('-', self)
        self.btn_mul = QPushButton('*', self)
        self.btn_div = QPushButton('/', self)
        self.init_ui()

    def init_ui(self):
        # Label for showing current result
        self.current.move(62, 10)
        self.current.resize(320, 30)
        # TextBox
        self.textbox.move(60, 60)
        self.textbox.resize(320, 40)
        # Addition Button
        self.btn_add.move(60, 100)
        self.btn_add.resize(80, 40)
        # Subtraction Button
        self.btn_sub.move(140, 100)
        self.btn_sub.resize(80, 40)
        # Multiplication Button
        self.btn_mul.move(220, 100)
        self.btn_mul.resize(80, 40)
        # Division Button
        self.btn_div.move(300, 100)
        self.btn_div.resize(80, 40)
        # Window Title
        self.setWindowTitle('Basit Hesap Makinesi')
        # Initiate UI
        self.show()
        # connect the signals to the slots
        self.btn_add.clicked.connect(self.addition)
        self.btn_sub.clicked.connect(self.subtraction)
        self.btn_mul.clicked.connect(self.multiplication)
        self.btn_div.clicked.connect(self.division)

    # Create the actions
    @pyqtSlot()
    def addition(self):
        self.result += float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText(str(self.result))

    @pyqtSlot()
    def subtraction(self):
        self.result -= float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText(str(self.result))

    @pyqtSlot()
    def multiplication(self):
        self.result *= float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText(str(self.result))

    @pyqtSlot()
    def division(self):
        self.result /= float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText(str(self.result))


def main():
    app = QApplication(sys.argv)
    start = SimpleCalculator()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
