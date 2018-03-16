from itertools import permutations
from math import sqrt


def sort_by_perfsq(arr):
    arr = sorted(arr)

    def get_sqrts(item):
        count = 0
        perms = set(permutations(str(item)))
        for possibility in perms:
            if sqrt((int(''.join(possibility)))).is_integer():
                count += 1
        return count

    return sorted(arr, key=get_sqrts, reverse=True)


print(sort_by_perfsq([234, 61, 16, 441, 144, 728]))

''' Alternate Solution 1:
from itertools import permutations

def sort_by_perfsq(a):
    return [x for _, x in sorted([(-sum(1 for c in set(permutations(str(n))) if (float(''.join(c)) ** 0.5).is_integer()), n) for n in a])]


Alternate 2:

from math import sqrt
from itertools import permutations

def sort_by_perfsq(a):
    return sorted(a, key = lambda n: (-sum(str(sqrt(int(''.join(p))))[-2:] =='.0' for p in set(permutations(str(n), len(str(n))))), n))

'''