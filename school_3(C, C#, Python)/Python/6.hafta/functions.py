# Note to myself: Memory error veren codewars sorusunu generator kullanarak cozebilir miyiz? bence cozebiliriz...
from functools import reduce
import time

t0 = time.clock()
a = reduce(lambda x, y: x * y, [i for i in range(1, 11)])
print("factorial: {0}".format(a))
print("time: {0}".format(time.clock() - t0))
print(list(map(lambda n: n ** 2, [i for i in range(10)])))
# print(2147483647 >= 5382703888)

# :.,+2s/foo/bar/g	    su anki satir ile 2 satir sonraki satirlar arasinda, "foo"yu "bar" olarak degistiren vim komut

# def us(x, n):
#     if n == 0: return 1
#     return x * us(x, n - 1)

# print(uc(2, 4))

def func(a, *args):
    print(args)
L = [2, 3]
func(10, *L)             # fonksiyon cagiriminda args kullanimi
func(1)

def fonk(*args):
    for sira, isim in enumerate(args):
        print("{0} --> {1}".format(sira, isim))

fonk("ahmet", "mehmet", "recep")

d = {1: "5", 2: "10"}
for key, value in d.items():
    print(key, value)

