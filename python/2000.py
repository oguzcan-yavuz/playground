fp = open("random.txt", "r")
result = 0
for i, line in enumerate(fp, 1):
    if i % 2000 == 0:
        result += int(line[15:])
print(result)
fp.close()
