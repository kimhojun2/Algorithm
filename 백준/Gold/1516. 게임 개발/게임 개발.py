from collections import deque


def game():
    q = deque()
    dp = [0]*N

    for i in range(N):
        if indegree[i] == 0:
            dp[i] = times[i]
            q.append(i)


    while q:
        now_game = q.popleft()

        for after_game in graph[now_game]:
            indegree[after_game] -= 1
            dp[after_game] = max(dp[after_game], dp[now_game] + times[after_game])
            if indegree[after_game] == 0:
                q.append(after_game)



    return dp



N = int(input())

graph = [[] for _ in range(N)]
times = [0]*N
indegree = [0]*N
for i in range(N):
    now = list(map(int, input().split()))
    times[i] = now[0]
    for before in now[1:]:
        if before == -1: break
        graph[before-1].append(i)
        indegree[i] += 1

ans = game()

for i in ans:
    print(i)