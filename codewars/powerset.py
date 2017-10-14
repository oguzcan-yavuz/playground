def powerset(nums):
    graph = {}
    for index, e in enumerate(nums):
        graph[str(e)] = [j for i, j in enumerate(nums) if i >= index]
    # {'1': [], '3': [1, 2], '2': [1]}
    # {'1': [1, 2, 3], '3': [3], '2': [2, 3]}
    print graph
    # # [[], [3], [2], [2, 3], [1], [1, 3], [1, 2], [1, 2, 3]]
    results = []


# print powerset([1, 2])          # [[], [2], [1], [1, 2]]
# print powerset([1, 2, 3])         # [[], [3], [2], [2, 3], [1], [1, 3], [1, 2], [1, 2, 3]]

# [[], [4], [3], [3,4], [2], [2,4], [2,3], [2,3,4], [1], [1,4], [1,3], [1,3,4], [1,2], [1,2,4], [1,2,3], [1,2,3,4]]
# print powerset([1, 2, 3, 4])
