from collections import deque
N, K = map(int, input().split())


def move(N, K):
    visited = [0] * 100001
    check = [0] * 100001
    q = deque()
    q.append(N)
    finish = False
    if N == K:
        finish = True

    while q:
        if finish == True:
            break

        t = q.popleft()
        for d in (t*2, t+1, t-1):
            if 0<= d < 100001:
                if check[d] == 0:
                    if d == t*2:
                        visited[d] = visited[t]

                    else:
                        visited[d] = visited[t] + 1
                    check[d] = 1
                    q.append(d)

                else:
                    if visited[d] >= visited[t] + 1:
                        if d == t*2:
                            visited[d] = visited[t]
                        else:
                            visited[d] = visited[t] + 1

                        q.append(d)

    print(visited[K])

move(N,K)