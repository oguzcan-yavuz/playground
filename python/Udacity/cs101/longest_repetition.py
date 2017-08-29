# Question 8: Longest Repetition

# Define a procedure, longest_repetition, that takes as input a
# list, and returns the element in the list that has the most
# consecutive repetitions. If there are multiple elements that
# have the same number of longest repetitions, the result should
# be the one that appears first. If the input list is empty,
# it should return None.


def longest_repetition(check):
    # return None if check is empty list
    if len(check) == 0:
        return None
    elif len(check) == 1:
        return check[0]
    # calculate repeats
    maximum, i = [], 0
    while i < len(check):
        temp, j = 0, i
        while j < len(check):
            if check[i] == check[j]:
                temp += 1
                j += 1
            else:
                break
        maximum.append([check[i], temp])
        i = j
    result = maximum[0]
    for i in maximum:
        if i[1] > result[1]:
            result = i
    return result[0]

print longest_repetition([2, 2, 3, 3, 3])
