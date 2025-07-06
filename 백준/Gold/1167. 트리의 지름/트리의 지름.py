import sys
sys.setrecursionlimit(10**6)


V = int(input())

tree = [[]for _ in range(V+1)]

for v in range(V):
    info = list(map(int, input().split()))
    s = info[0]
    idx = 1
    while True:
        if info[idx] == -1: break
        e, v = info[idx], info[idx+1]
        tree[s].append((e,v))
        idx += 2

def dfs(start, distance):
    for next, dist in tree[start]:
        if visited[next] != -1: continue
        visited[next] = distance + dist
        dfs(next, distance+dist)



visited = [-1] * (V+1)
visited[1] = 0
dfs(1,0)

new_node = visited.index(max(visited))
visited = [-1] * (V+1)
visited[new_node] = 0
dfs(new_node, 0)

print(max(visited))