def f(n):
    res = 1
    for i in range(n, 1, -1):
        res *= i
    return res


n = int(input())

values = []
for _ in range(n):
    values.append(int(input()))

for val in values:
    print(f(val))
