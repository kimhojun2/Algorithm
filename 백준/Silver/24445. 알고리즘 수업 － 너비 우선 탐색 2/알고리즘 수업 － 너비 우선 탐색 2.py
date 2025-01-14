from collections import deque


N,M,R = map(int, input().split())

dic = {}

for i in range(M):
    s,e = map(int, input().split())
    if s not in dic:
        dic[s] = [e]
    else:
        dic[s].append(e)

    if e not in dic:
        dic[e] = [s]
    else:
        dic[e].append(s)


for value in dic.values():
    value.sort(reverse=True)

visited = [0] *(N+1)

def bfs(start):
    q = deque()
    q.append(start)
    step = 1
    visited[start] = step

    while q:
        now = q.popleft()
        for next in dic.get(now,{}):
            if not visited[next]:
                step +=1
                visited[next] = step
                q.append(next)

bfs(R)

for i in range(1,N+1):
    print(visited[i])