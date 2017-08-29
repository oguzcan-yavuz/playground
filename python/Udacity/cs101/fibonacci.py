def fibonacci(n):
    current, after = 0, 1
    for i in range(0, n):
        current, after = after, current + after
    return current
    
print(fibonacci(5))