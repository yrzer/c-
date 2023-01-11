import zipfile

def cos(pswd):
    try:
        with zipfile.ZipFile("zpi.zip") as file:
            file.extractall(pwd = bytes(pswd, 'utf-8'))
    except: return False
    print(pswd)
    exit()
while True:
    for x1 in range(128):
        for x2 in range(128):
            for x3 in range(128):
                for x4 in range(128):
                    for x5 in range(128):
                        for x6 in range(128):
                            for x7 in range(128):
                                for x8 in range(128):
                                    txt=""
                                    if x8!=0: txt+=chr(x8)
                                    if x7!=0: txt+=chr(x7)
                                    if x6!=0: txt+=chr(x6)
                                    if x5!=0: txt+=chr(x5)
                                    if x4!=0: txt+=chr(x4)
                                    if x3!=0: txt+=chr(x3)
                                    if x2!=0: txt+=chr(x2)
                                    if x1!=0: txt+=chr(x1)
                                    print(txt)
                                    if cos(txt):  
                                        print(txt)
                                        exit()
                                    if x8 == "c" and x7 == "o" and x6 == "s": a = input("cos")
    break
