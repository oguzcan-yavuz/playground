# ------------------
# User Instructions
#
# Hopper, Kay, Liskov, Perlis, and Ritchie live on
# different floors of a five-floor apartment building.
#
# Hopper does not live on the top floor.
# Kay does not live on the bottom floor.
# Liskov does not live on either the top or the bottom floor.
# Perlis lives on a higher floor than does Kay.
# Ritchie does not live on a floor adjacent to Liskov's.
# Liskov does not live on a floor adjacent to Kay's.
#
# Where does everyone live?
#
# Write a function floor_puzzle() that returns a list of
# five floor numbers denoting the floor of Hopper, Kay,
# Liskov, Perlis, and Ritchie.

import itertools


def floor_puzzle():
    floors = [1, 2, 3, 4, 5]
    for digits in itertools.permutations(floors, 5):
        if (digits[0] != 5
            and digits[1] != 1
            and digits[2] != 1
            and digits[2] != 5
            and digits[3] > digits[1]
            and abs(digits[4] - digits[2]) > 1
            and abs(digits[2] - digits[1]) > 1):
            return list(digits)


print floor_puzzle()
