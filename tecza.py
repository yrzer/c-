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
    if c == "b":
        return '\33[30m' #black
p_line = ""
for x in range(6):
    p_line+= style(x)+"*"
bla = style("b")+"*"
os.system('cls')
sleep(1)
# wysokość 16 # grubość 6 # 
# 7s  8-11s2 12-15s3 ostatnia wzór i odwrót
e = []
for x in range(16):
    e.append(bla*3)
a=15
l,q,w,k = 0,0,0,0
for x in reversed(range(16)):
    l+=1
    k=bla*l
    e[x] +=(bla*l)+p_line
    chw=""
    if x in range(10) : 
        q+=1
        for mx in range(q): chw += bla
    if x in range(6) : 
        w+=1
        for mx in range(w): chw += bla
    k+=chw
    e[x-1] += chw
chw = ""
for x in [0,1,2,0,4,3,2,1,0]:
    chw+=style(x)+"*"
chwla=k+chw
print(len(chw))
'''
bla=bla+bla
l,q,w = 0,0,0
for x in range(16):
    l+=1
    e[x] +=(bla*l)+p_line
    chw=""
    if x in range(10) : 
        q+=1
        for mx in range(q): chw += bla
    if x in range(6) : 
        w+=1
        for mx in range(w): chw += bla
    e[x-1] += chw
'''



for x in range(16):
    print(e[x])
input("press any key")