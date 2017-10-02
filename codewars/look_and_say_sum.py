def look_and_say_and_sum(n):
    start, result = "1", 0
    for _ in range(n - 1):
        length = len(start)
        j, current = 0, ""
        while j < length:
            count = 1
            while j < length - 1 and start[j] == start[j + 1]:
                count += 1
                j += 1
            current += str(count) + start[j]
            j += 1
        start = current
    for i in start:
        result += int(i)
    return result


print(look_and_say_and_sum(55))
