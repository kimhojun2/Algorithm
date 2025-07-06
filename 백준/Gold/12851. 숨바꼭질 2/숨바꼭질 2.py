from collections import deque

def BFS(N,K):
    visited = [0] * (100001)
    queue = deque()
    queue.append(N)
    result = 0
    cnt = 0
    if N == K:
        cnt += 1
        result = 1
    while queue:
        if result == 1:
            break
        t = queue.popleft()
        if K == t:
            cnt +=1



        for i in (t-1, t+1, t*2):
            if 0 <= i < 100001:
                if visited[i] == 0:
                    visited[i] = visited[t] + 1
                    queue.append(i)
                elif visited[i] == visited[t]+1:
                    visited[i] = visited[t] + 1
                    queue.append(i)

    print(visited[K])
    print(cnt)

N,K=map(int,input().split())
BFS(N,K)
