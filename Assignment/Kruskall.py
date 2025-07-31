G = [
    [0, 2, 3],
    [0, 1, 2],
    [0, 3, 3],
    [1, 0, 2],
    [1, 2, 4],
    [1, 4, 3],
    [2, 0, 3],
    [2, 1, 4],
    [2, 3, 5],
    [2, 4, 1],
    [3, 0, 3],
    [3, 2, 5],
    [3, 5, 7],
    [4, 1, 3],
    [4, 2, 1],
    [4, 5, 8],
    [5, 3, 7],
    [5, 4, 8],
    [5, 6, 9],
    [6, 5, 9],
]

def find(parent, vertex):
    if parent[vertex] == vertex:
        return vertex
    return find(parent, parent[vertex])

def union(parent, height, x, y):
    xroot = find(parent, x)
    yroot = find(parent, y)

    if height[xroot] < height[yroot]:
        parent[xroot] = yroot
    elif height[yroot] < height[xroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        height[xroot] += 1

def kruskall(G, n):
    result = []
    e = 0
    i = 0
    parent = []
    height = []

    tree = sorted(G, key = lambda x: x[2])

    for node in range(n):
        parent.append(node)
        height.append(0)
    
    while e < n-1:
        node1, node2, weight = tree[i]
        i+=1
        x_parent = find(parent, node1)
        y_parent = find(parent, node2)

        if(x_parent != y_parent):
            result.append([node1, node2, weight])
            e+=1
            union(parent, height, x_parent, y_parent)
    return result

result = kruskall(G, 7)
print(result)
for u, v, w in result:
    print(f"{u} - {v} : {w}")

