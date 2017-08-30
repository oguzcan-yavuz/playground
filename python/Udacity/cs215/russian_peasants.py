def russian(x, y):
    z = 0
    while x > 0:
        if x % 2 == 1:
            z += y
        y = y << 1
        x = x >> 1
    return z


def rec_russian(x, y):
    if x == 0:
        return x
    if x % 2 == 0:
        return 2 * rec_russian(x / 2, y)
    else:
        return y + 2 * rec_russian((x - 1) / 2, y)


print(russian((2 ** 123), (3 ** 312)))
print(rec_russian(2 ** 123, 3 ** 312))
