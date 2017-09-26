import this
import string

print()
print(type(string))
print(type(str))

print(ord('Ç'))     # 199

n = 123
print(id(123))      # 10775424 n degiskeninin anabellekteki adresini verir


# Python'da integer degerler tek bir adrese atanir. bu degerlerin birden fazla degisken adi olabilir.
# Ancak bu degiskenlerin her biri bellekte ayni adresi isaret eder.
a = 1
b = 1
c = 1
d = 2

print(id(1))    # 10771520
print(id(a))    # 10771520
print(id(b))    # 10771520
print(id(c))    # 10771520
print(id(d))    # 10771552

b += 3
print(id(a))    # 10771520
print(id(b))    # 10771516
