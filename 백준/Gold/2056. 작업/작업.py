from collections import deque,defaultdict


def work():
    q = deque()
    dp = [0]*(N+1)

    for i in range(1,N+1):
        if indegree[i] == 0:
            q.append(i)
            dp[i] = times[i]

    while q:
        now_work = q.popleft()

        for next_work in graph[now_work]:
            indegree[next_work] -= 1
            dp[next_work] = max(dp[next_work], dp[now_work] + times[next_work])
            if indegree[next_work] == 0:
                q.append(next_work)

    return max(dp)


N = int(input())
graph = defaultdict(list)
times = [0] * (N+1)
indegree = [0] * (N+1)

for i in range(1, N+1):
    if i == 1:
        t, root = map(int, input().split())
        times[1] = t

    else:
        now = list(map(int, input().split()))
        times[i] = now[0]
        indegree[i] += now[1]
        for j in now[2:]:
            graph[j].append(i)


print(work())