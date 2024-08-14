
from collections import deque
N = int(input())

tree = {i:[] for i in range(1, N+1)}
visited = [0] *(N+1)
for i in range(N-1):
    a, b = map(int, input().split())
    if a == 1 or b == 1:
        if a == 1:
            tree[1].append(b)
        else:
            tree[1].append(a)
        continue

    tree[a].append(b)
    tree[b].append(a)



ans = [0] * (N-1)
def find():
    q = deque([1])
    while q:
        now = q.popleft()
        visited[now] = 1
        for i in tree[now]:
            if not visited[i]:
                q.append(i)
                visited[i] = 1
                ans[i-2] = now



find()

for root in ans:
    print(root)