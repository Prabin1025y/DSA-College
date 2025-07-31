import math
import pprint

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

def prims(G, n):
    parents = [-1 for _ in range(n)]
    in_mst = [False for _ in range(n)]
    key_values = [math.inf for _ in range(n)]
    result = [[math.inf for _ in range(n)] for _ in range(n)]

    for row in G:
        x,y,w = row
        result[x][y] = w
        result[y][x] = w
    
    # pprint.pprint(result)


    key_values[0] = 0

    for _ in range(n):
        mst_node_candidates = (v for v in range(n) if not in_mst[v])
        mst_node = min(mst_node_candidates, key=lambda x: key_values[x])

        in_mst[mst_node] = True
        # print(key_values)

        if parents[mst_node] != -1:
            print(f"{parents[mst_node]} - {mst_node} : {result[mst_node][parents[mst_node]]}")
        
        for v in range(n):
            if result[mst_node][v] < key_values[v] and not in_mst[v]:
                key_values[v] = result[mst_node][v]
                parents[v] = mst_node
    # pprint.pprint(in_mst)
prims(G, 7)



        
