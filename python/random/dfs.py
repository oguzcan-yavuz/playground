graph = {
    'A': ['G', 'B', 'D'],
    'B': ['F', 'E'],
    'C': ['H', 'F'],
    'D': ['F', 'A'],
    'E': ['B', 'G'],
    'F': ['B', 'D', 'C'],
    'G': ['E', 'A'],
    'H': ['C']
}

visited = []
starter = min(graph.keys())

def dfs(node):
    if node not in visited:
        visited.append(node)
    for key in sorted(graph[node]):
        if key not in visited:
            visited.append(key)
            dfs(key)

dfs(starter)
print(visited)
