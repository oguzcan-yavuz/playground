def thue_morse(n):
    morse = "0"
    for i in range(n - 1):
        if 2 ** i < n:
            for i in range(2 ** i):
                morse += "1" if morse[i] == "0" else "0"
    return morse[:n]
