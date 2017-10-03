# -*- coding: utf-8 -*-
# -*- coding: cp1254 -*-

a = raw_input("a\n")
b = raw_input("b\n")
print(a + b)
x = input("x\n")
y = input("y\n")
print("%d" % (x + y))

my_list = [1, 2, 3]
print("%s" % my_list)

print(my_list * 3)      # [1, 2, 3, 1, 2, 3, 1, 2, 3]

t = str(input("lol\n"))
print(t)        # python 2'de calismaz. string almak icin raw_input() kullanmak lazim

print(my_list is [1, 2, 3])     # False

test = "sa"          # int gibi string degerler de bellekte ayni adreste tutuluyor
print(test is "sa")


# instance example
class TestClass:
    def __init__(self):
        pass


test = TestClass()
print(type(test))       # instance


import random
mod = random.randrange(100)
if mod == 0 or mod == 2:
    print mod
else:
    print "yanlis mod degeri"
