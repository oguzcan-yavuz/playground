import math


def calculate_area(x, y):
    if x < 0:
        return 90 if y < 0 else 0
    else:
        return 180 if y < 0 else 270


def get_score(x, y):
    distance = ((x ** 2) + (y ** 2)) ** 0.5
    if distance <= 6.35:
        return "DB"
    elif distance <= 15.9:
        return "SB"
    elif distance >= 170:
        return "X"
    # calculate angle
    pure_angle = math.degrees(math.atan(float(y) / x))
    angle = (pure_angle if pure_angle > 0 else 90 + pure_angle) + calculate_area(x, y)
    scores = [20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10, 6, 13, 4, 18, 1]
    # divide the dart to 20 partition with 18 degrees each
    partitions = []
    for i in range(-9, 351, 18):
        partitions.append([i, i + 18])
    # calculate the hit partition
    hit = 0
    for i, ranges in enumerate(partitions):
        if ranges[0] <= angle <= ranges[1]:
            hit = i
            break
    # get the score from score table of hit dart partition
    score = scores[hit]
    result = str(score)
    # check distances
    circle_distances = [[3, [99, 107]], [2, [162, 170]]]
    for multiplier, dist in circle_distances:
        if dist[0] <= distance <= dist[1]:
            result = ""
            result += ("T" if multiplier == 3 else "D") + str(score)
            return result
    return result


''' ALTERNATIVE SOLUTION

from math import atan2, degrees

def get_score(x,y):
    r, a = (x*x + y*y)**0.5, degrees(atan2(y, x)) + 9
    t = str([6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10][int(a + 360 if a < 0 else a)//18])
    for l, s in [(6.35, 'DB'),(15.9,'SB'),(99,t),(107,'T'+t),(162,t),(170,'D'+t)]:
        if r <= l: return s
    
    return 'X' 
    
'''
