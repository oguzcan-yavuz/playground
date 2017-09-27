def make_valley(arr):
    arr = sorted(arr, reverse=True)
    i = 0
    left, right = [], []
    while i < len(arr) - 2 if len(arr) % 2 != 0 else i < len(arr) - 1:
        left.append(arr[i])
        right.append(arr[i + 1])
        i += 2
    return left + [min(arr)] + right[::-1] if len(arr) % 2 != 0 else left + right[::-1]


print(make_valley([20, 7, 6, 2, 1]))
