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
        self.textbox = QLineEdit('', self)
        # Buttons
        self.btn_add = QPushButton('+', self)
        self.btn_sub = QPushButton('-', self)
        self.btn_mul = QPushButton('*', self)
        self.btn_div = QPushButton('/', self)
        self.btn_c = QPushButton('C', self)
        self.init_ui()

    def init_ui(self):
        # Label for showing current result
        self.current.move(62, 10)
        self.current.resize(160, 40)
        # TextBox
        self.textbox.move(60, 60)
        self.textbox.resize(160, 40)
        self.textbox.setValidator(QIntValidator())
        # Addition Button
        self.btn_add.move(60, 100)
        self.btn_add.resize(80, 40)
        # Subtraction Button
        self.btn_sub.move(140, 100)
        self.btn_sub.resize(80, 40)
        # Multiplication Button
        self.btn_mul.move(60, 140)
        self.btn_mul.resize(80, 40)
        # Division Button
        self.btn_div.move(140, 140)
        self.btn_div.resize(80, 40)
        # Reset Button
        self.btn_c.move(140, 180)
        self.btn_c.resize(80, 40)
        # connect the signals to the slots
        self.btn_add.clicked.connect(self.addition)
        self.btn_sub.clicked.connect(self.subtraction)
        self.btn_mul.clicked.connect(self.multiplication)
        self.btn_div.clicked.connect(self.division)
        self.btn_c.clicked.connect(self.reset)
        # Window Title
        self.setWindowTitle('Basit Hesap Makinesi')
        # Initiate UI
        self.show()

    # Create the actions
    @pyqtSlot()
    def addition(self):
        self.result += float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText("")
        self.textbox.setFocus()

    @pyqtSlot()
    def subtraction(self):
        self.result -= float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText("")
        self.textbox.setFocus()

    @pyqtSlot()
    def multiplication(self):
        self.result *= float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText("")
        self.textbox.setFocus()

    @pyqtSlot()
    def division(self):
        self.result /= float(self.textbox.displayText())
        self.current.setText(str(self.result))
        self.textbox.setText("")
        self.textbox.setFocus()

    @pyqtSlot()
    def reset(self):
        self.result = 0.0
        self.current.setText("0.0")
        self.textbox.setText("")
        self.textbox.setFocus()


def main():
    app = QApplication(sys.argv)
    start = SimpleCalculator()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
