def int_to_negabinary(i):
    remainders = ""
    while True:
        remainders += str(int(i % 2))
        if i == 1 or i == 0:
            break
        i = i / 2 * -1
    return remainders[::-1]


def negabinary_to_int(s):
    result = 0
    s = s[::-1]
    for i in range(len(s)):
        if s[i] == "1":
            result += (-2) ** i
    return result

print int_to_negabinary(2731)
print negabinary_to_int("1110")