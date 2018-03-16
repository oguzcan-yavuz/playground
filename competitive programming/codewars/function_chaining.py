class CustomInt(int):
    def __call__(self, n):
        return CustomInt(self + n)


def add(n):
    return CustomInt(n)
    

print(add(3))
print(add(3)(5))
print(add(3)(5)(13))
