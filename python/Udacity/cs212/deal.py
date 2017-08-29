import random

mydeck = [r + s for r in "23456789TJQKA" for s in "SHDC"]

def deal(numhands, n = 5, deck = mydeck):
    random.shuffle(deck)
    return [deck[n * i: n * (i + 1)] for i in range(numhands)]
    
print deal(2)
