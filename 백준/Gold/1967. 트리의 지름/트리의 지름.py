import sys
sys.setrecursionlimit(10**6)

n = int(input())

tree = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    p, c, d = map(int, input().split())
    tree[p].append((c, d))
    tree[c].append((p, d))


def dfs(start, distance):
    for next, dist in tree[start]:
        if visited[next] != -1: continue
        visited[next] = distance + dist
        dfs(next, distance+dist)



visited = [-1] * (n+1)
visited[1] = 0
dfs(1,0)

new_node = visited.index(max(visited))

visited = [-1] * (n+1)
visited[new_node] = 0
dfs(new_node,0)
print(max(visited))