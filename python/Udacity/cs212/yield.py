def ints(start, end=None):
    i = start
    while start <= end or end is None:
        yield i
        i += 1
        
def all_ints():
    yield 0
    for i in ints(1):
        yield +i
        yield -i
        
    '''
    yield 0
    i = 1
    while True:
        yield +i
        yield -i
        i += 1
    '''