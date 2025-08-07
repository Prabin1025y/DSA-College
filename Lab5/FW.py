from pprint import pprint
import math

G = [
    [0, 10, math.inf, 5, math.inf],
    [math.inf, 0, 1, 2, math.inf],
    [math.inf, math.inf, 0, math.inf, 4],
    [math.inf, 3, 9, 0, 2],
    [7, math.inf, 6, math.inf, 0],
]


def FloydWarshall(W):
    n = len(W)
    D = {}
    prev = {}
    D[-1] = W

    prev[-1] = [
        [-1, 0, -1, 0, -1],
        [-1, -1, 1, 1, -1],
        [-1, -1, -1, -1, 2],
        [-1, 3, 3, -1, 3],
        [4, -1, 4, -1, -1],
    ]

    for k in range(n):
        D[k] = D[k - 1]
        prev[k] = prev[k-1]
        # print(D[k-1])
        for i in range(n):
            for j in range(n):
                D[k][i][j] = min(D[k - 1][i][j], D[k - 1][i][k] + D[k - 1][k][j])
                if D[k - 1][i][j] > D[k - 1][i][k] + D[k - 1][k][j]:
                    prev[i-1]
                
    print(prev)
    return D[k]


ans = FloydWarshall(G)
pprint(ans)
