#!/usr/bin/python3

import pyautogui
import time

coordinates = pyautogui.position()

while True:
	pyautogui.click(coordinates)
	time.sleep(0.1)

