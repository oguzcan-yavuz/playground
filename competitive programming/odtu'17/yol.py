from math import sqrt, degrees, acos


def hip_gen(x, y):
    return sqrt((x ** 2) + (y ** 2))


def angle_gen(x1, y1, x2, y2):
    dot_product = (x1 * x2) + (y1 * y2)
    hip1 = hip_gen(x1, y1)
    hip2 = hip_gen(x2, y2)
    return degrees(acos(dot_product / (hip1 * hip2)))


angles = []

first_map = [2, -6, -4, -6, -4, -2, 4, -2, 4, 4, 2, 4]
second_map = [3, -4, 3, 4, -3, 4, -3, 2, 7, 2, 7, -4]
# first_map = [1, 4, 5, 7, 5, 2, -3, -4, -3, -9, 1, -6]
# second_map = [5, 1, -5, 1, -8, -3, -3, -3, 3, 5, 8, 5]

for i in range(0, len(first_map), 2):
    angles.append(angle_gen(first_map[i], first_map[i + 1], second_map[i], second_map[i + 1]))


print(sum(angles))

# angle_sum_1 = 570.0596901043315
# angle_sum_2 = 645.7805607543016
