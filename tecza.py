import os
from time import sleep
os.system("")
def style(c):
    if c == 0:
        return '\33[31m' #red
    elif c == 1: 
        return '\33[33m' #yellow
    elif c == 2: 
        return '\33[32m' #green
    elif c == 4:
        return '\33[34m' #blue
    elif c == 5:
        return '\33[35m' #violet
    if c == 3:
        return '\33[0m' #reset
os.system('cls')
sleep(1)
# wysokość 16 # grubość 6 # 
# 7s  8-11s2 12-15s3 ostatnia wzór i odwrót  



input("press any key")