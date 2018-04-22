from math import sqrt


def distances(i, j):
    a = abs(i - 4) + 0.5 if i <= 4 else -0.5
    b = j + ((6.5 + 2.8) / 4.8) - 0.5
    return a, b

def pythagorean(x, y):
    return sqrt((x * x) + (y * y));

def h():
    r = []
    for i in range(8):
        for j in range(8):
            x, y = distances(i, j)
            r.append(pythagorean(x, y) * 4.8)
    print(set(sorted(r)))

def main():
    h()

main()
