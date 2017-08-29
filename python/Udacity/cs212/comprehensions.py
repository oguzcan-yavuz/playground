xx = [1, 2, 3, 4]
liste = [x if x > 10 else x + 1 for x in xx]
liste2 = [x for x in xx if x < 3]
# print "liste1: %s" % liste
# print "liste2: %s" % liste2

squares1 = list(map(lambda x: x**2, range(10)))
squares2 = [x**2 for x in range(10)]
print(squares1)
print(squares2)
