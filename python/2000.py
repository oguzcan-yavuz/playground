fp = open("random.txt", "r")        # random.txt line example: 1234 5678 1234 5678
result = 0
for i, line in enumerate(fp, 1):
    # if we are at the 2000th line
    if i % 2000 == 0:
        # last 4 digit number is our result.
        result = int(line[15:])
print(result)
fp.close()
