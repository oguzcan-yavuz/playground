# --------------
# User Instructions
#
# Write a function, longest_subpalindrome_slice(text) that takes
# a string as input and returns the i and j indices that
# correspond to the beginning and end indices of the longest
# palindrome in the string.
#
# Grading Notes:
#
# You will only be marked correct if your function runs
# efficiently enough. We will be measuring efficency by counting
# the number of times you access each string. That count must be
# below a certain threshold to be marked correct.
#
# Please do not use regular expressions to solve this quiz!


def longest_subpalindrome_slice(text):
    # "Return (i, j) such that text[i:j] is the longest palindrome in text."
    if text == '': return 0, 0

    text, results, i, j = text.lower(), [], 0, 1
    length = len(text)

    def check(slice):
        a, b = slice
        return b - a

    while j < length:
        second_i = i
        control = False
        border = False
        while (i >= 0 and j < length) and (text[i] == text[j] or (j + 1 < length and text[i] == text[j + 1])):
            if j + 1 < length and text[i] == text[j + 1]:
                j += 1
            results.append((i, j + 1))
            i -= 1
            j += 1
            control = True
            # border control
            if (i < 0 and j < length) or (j > length and i >= 0):
                control = False
                border = True
        if control:
            i = j
            j = i + 1
        elif border:
            i = second_i + 1
            j = i + 1
        else:
            i += 1
            j += 1
    return max(results, key=check)


def test():
    L = longest_subpalindrome_slice
    assert L('racecar') == (0, 7)
    assert L('Racecar') == (0, 7)
    assert L('RacecarXrr') == (0, 7)

    assert L('Race carr') == (7, 9)
    assert L('') == (0, 0)
    assert L('something rac e car going') == (8, 21)

    assert L('xxxxx') == (0, 5)
    assert L('Mad am I ma dam.') == (0, 15)
    return 'tests pass'


print test()

# Sensei's solution:

'''
def longest_subpalindrome(text):
    if text == '': return (0, 0)
    def length(slice): a, b = slice; return b - a
    candidates = [grow(text, start, end)
                  for start in range(len(text))
                  for end in (start, start + 1)]
    return max(candidates, key=length)

def grow(text, start, end):
    while (start > 0 and end < len(text)
           and text[start - 1].upper() == text[end].upper()):
        start -= 1; end += 1
    return (start, end)
'''
