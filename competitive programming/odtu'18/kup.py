from itertools import combinations


def create_cube(current_cubes, candidate):
    candidates = rotate_cube(candidate)
    for cube in candidates:
        if cube not in current_cubes:
            current_cubes.append(cube)
    return current_cubes


def rotate_cube(candidate):
    return [[]]


def main():
    input()
    colors = [int(e) for e in input().split(" ")]
    combs = combinations(colors, 6)
    cubes = []
    for comb in combs:
        cubes = create_cube(cubes, list(comb))
    print(len(cubes))


if __name__ == '__main__':
    main()
