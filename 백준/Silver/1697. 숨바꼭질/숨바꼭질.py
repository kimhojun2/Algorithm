from collections import deque

def BFS(s,e):
    visited = [0] * (100001)
    queue = deque()
    queue.append(s)
    while queue:
        t = queue.popleft()
        if e == t:
            print(visited[e])
            break

        for i in (t-1, t+1, t*2):
            if 0 <= i < 100001 and visited[i] == 0 :
                visited[i] = visited[t]+1
                queue.append(i)

s,e=map(int,input().split())
BFS(s,e)