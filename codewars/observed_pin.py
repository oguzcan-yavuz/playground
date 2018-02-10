def recursive_loop(arr, level, possibility, results):
    if level == 1:
        for i in arr[0]:
            results.append(possibility + i)
    else:
        for i in arr[0]:
            recursive_loop(arr[1:], level - 1, possibility + i, results)
        return results


def get_pins(observed):
    nums = {
        '1': ['1', '2', '4'],
        '2': ['1', '2', '3', '5'],
        '3': ['2', '3', '6'],
        '4': ['1', '4', '5', '7'],
        '5': ['2', '4', '5', '6', '8'],
        '6': ['3', '5', '6', '9'],
        '7': ['4', '7', '8'],
        '8': ['5', '7', '8', '9', '0'],
        '9': ['6', '8', '9'],
        '0': ['0', '8'],
    }
    all_candidates = [nums[num] for num in observed]
    possibilities = recursive_loop(all_candidates, len(all_candidates), "", [])
    return possibilities


res = get_pins('369')
print(res)

"""
***************** LIKE A BOSS **************************
from itertools import product

ADJACENTS = ('08', '124', '2135', '326', '4157', '52468', '6359', '748', '85790', '968')

def get_pins(observed):
    return [''.join(p) for p in product(*(ADJACENTS[int(d)] for d in observed))]

********************************************************


******** GENERATOR VERSION by Yengas **********************


def get_pins(observed):
    return [''.join(p) for p in product(*(ADJACENTS[int(d)] for d in observed))]def recursive_loop(arr, level, possibility, results):
    if level == 1:
        for i in arr[0]:
            yield (possibility + i)
    else:
        for i in arr[0]:
            yield from recursive_loop(arr[1:], level - 1, possibility + i, results)

def get_pins(observed):
    nums = {
        '1': ['1', '2', '4'],
        '2': ['1', '2', '3', '5'],
        '3': ['2', '3', '6'],
        '4': ['1', '4', '5', '7'],
        '5': ['2', '4', '5', '6', '8'],
        '6': ['3', '5', '6', '9'],
        '7': ['4', '7', '8'],
        '8': ['5', '7', '8', '9', '0'],
        '9': ['6', '8', '9'],
        '0': ['0', '8'],
    }
    all_candidates = [nums[num] for num in observed]
    possibilities = recursive_loop(all_candidates, len(all_candidates), "", [])
    return possibilities


res = list(get_pins('369'))
print(res)

**************************************************************
"""
