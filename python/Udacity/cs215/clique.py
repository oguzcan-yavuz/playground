#
# How many edges in a complete graph on n nodes?
# n - m + r = 2 BITCHEZ!
#


def clique(n):
    # Return the number of edges
    # Try to use a mathematical formula...
    return n * (n - 1) / 2


print(clique(6))
