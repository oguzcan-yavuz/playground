def find_eulerian_tour(graph):
    # find the node with biggest degree
    biggest_degree, biggest_node = 0, None
    for i, node in enumerate(graph):
        for e in node:
            count = 0
            outer_graph = graph[:]
            for inner_node in outer_graph:
                if e in inner_node:
                    count += 1
            if count > biggest_degree:
                biggest_degree = count
                biggest_node = e

    # set the starting point
    result = []
    for i, node in enumerate(graph):
        if biggest_node == node[0]:
            result = [node[0], node[1]]
            current_node = node[1]
            graph.pop(i)
            break

    # find the eulerian tour
    i = 0
    while i < len(graph):
        if current_node == graph[i][0] or current_node == graph[i][1]:
            current_node = (graph[i][1] if current_node == graph[i][0] else graph[i][0])
            result.append(current_node)
            graph.pop(i)
            i = 0
        else:
            i += 1
    return result


print(find_eulerian_tour(
    [
        (0, 1), (1, 5), (1, 7), (4, 5),
        (4, 8), (1, 6), (3, 7), (5, 9),
        (2, 4), (0, 4), (2, 5), (3, 6), (8, 9)
    ]
))
