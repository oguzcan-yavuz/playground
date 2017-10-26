kume = set("ankara")
kume2 = kume

print(kume)
kume2.clear()   # kume2 kume'nin pointeri olarak calisiyor, bu yuzden kume2'yi clear() ile temizledigimizde kume de temizleniyor.
print(kume)
print("pointer example ends here...\n")
# print(dir(kume))

k1 = set([1, 2, 3, 4])
k2 = set([10, 12, 3, 4])
k1.difference_update(k2)    # converts k1 to {1, 2}, returns None
print(k1)

# discard vs remove: eger silinmek istenen eleman kumede yoksa discard hicbir sey yapmaz, remove KeyError verir.

k1 = set([1, 2, 3, 4])
print("using minus sign")
print(k1 - k2)      # equals to: k1.difference(k2)
print(k1 & k2)      # equals to k1.intersection(k2)

print("k1 ile k2'nin butun elemanlari kesismiyor?: {0}".format(k1.isdisjoint(k2)))  # k1 ile k2'nin kesisen elemani yoksa True, varsa False dondurur.
print("k1, k2'in alt kumesi?: {0}".format(k1.issubset(k2)))
print("k1, k2'nin superseti?: {0}".format(k1.issuperset(k2)))

# frozenset -> read-only sets
frozen = frozenset([1, 2, 3])
print(frozen)
