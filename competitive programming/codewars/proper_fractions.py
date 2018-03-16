from fractions import gcd


def inspect(n):
    return [2] if n % 2 == 0 else [] + [i for i in range(3, int(round(n ** 0.5)) + 2, 2) if n % i == 0]
    # for i in range(2, (n / 2) + 1):
    #     print n, i, gcd(n, i)


def prime_test(n):
    if n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    j = 5
    while j * j <= n:
        if n % j == 0 or n % (j + 2) == 0:
            return False
        j += 6
    return True


def proper_fractions(n):
    if n == 1 or n == 2: return n - 1
    if prime_test(n):
        return n - 1
    count = 1
    for i in range(2, (n / 2) + 1):
        if gcd(n, i) == 1:
            count += 1
    return count * 2

print(proper_fractions(500000003))
# print inspect(123)
# print inspect(222)
# print inspect(9)
# print inspect(99)
# print inspect(999)
# print inspect(9999)
# print inspect(99999)
# print inspect(999999)
# print proper_fractions(9)
# print proper_fractions(99)
# print proper_fractions(999)
# print proper_fractions(9999)
# print proper_fractions(99999)
# print proper_fractions(999999)
# print proper_fractions(9999999)
# print proper_fractions(99999999)
# print proper_fractions(1)
# print proper_fractions(12)
# print proper_fractions(123)
# print proper_fractions(1234)
# print proper_fractions(12345)
# print proper_fractions(123456)
# print proper_fractions(1234567)

# print proper_fractions(123456789)   # == 82260072
# print proper_fractions(9999999999)      # next text case
# print proper_fractions(500000003)
# print proper_fractions(12)
# print proper_fractions(15)
# print proper_fractions(5)
# print proper_fractions(25)



