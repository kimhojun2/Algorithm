from collections import deque

T = int(input())

for tc in range(T):
    K,M,P = map(int, input().split())
    graph = [[]for _ in range(M+1)]
    indegree = [0]*(M+1)
    for p in range(P):
        A,B = map(int, input().split())
        graph[A].append(B)
        indegree[B] += 1

    Strahler = [[0,0]for _ in range(M+1)]
    q = deque()
    for i in range(1,M+1):
        if indegree[i] == 0:
            Strahler[i] = [1,1]
            q.append(i)

    while q:
        now = q.popleft()

        for next in graph[now]:
            indegree[next] -= 1
            if Strahler[now][0] > Strahler[next][0]:
                Strahler[next][0] = Strahler[now][0]
                Strahler[next][1] = 1
            elif Strahler[now][0] == Strahler[next][0]:
                Strahler[next][1] += 1

            if indegree[next] == 0:
                if Strahler[next][1] > 1:
                    Strahler[next][0] += 1
                q.append(next)

    print(K,Strahler[M][0])