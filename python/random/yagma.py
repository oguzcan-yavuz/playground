#!/usr/bin/python3

import time
import threading

from pynput import keyboard
from pynput.mouse import Button, Controller

mouse = Controller()
print(mouse.position)
refresh_button = mouse.position
attack_button = (980, 275)

def refresher(e):
    while not e.isSet():
        mouse.position = refresh_button
        mouse.click(Button.left, 1)
        time.sleep(0.2)

e = threading.Event()
t = threading.Thread(target=refresher, args=(e, ))
t.start()

def attack(key):
    if key == keyboard.Key.esc:
        print("Program kapatiliyor!")
        e.set()
        return False
    elif key == keyboard.Key.space:
        print("Saldiri yapiliyor!\n50 kupon is coming xd")
        e.set()
        mouse.position = attack_button
        time.sleep(0.1)
        mouse.position = (200, 200)
        time.sleep(0.1)
        mouse.position = attack_button
        time.sleep(0.1)
        mouse.click(Button.left, 1)
        mouse.click(Button.left, 1)
        mouse.click(Button.left, 1)
        mouse.click(Button.left, 1)
        return False

with keyboard.Listener(on_press=attack) as listener:
    listener.join()
