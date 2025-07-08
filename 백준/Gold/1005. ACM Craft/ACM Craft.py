from collections import defaultdict, deque
import sys
input = sys.stdin.readline

def ACMcraft():
    dp = [0] * (N+1)
    q = deque()

    for i in range(1, N+1):
        if indegree[i] == 0:
            dp[i] = times[i-1]
            q.append(i)


    while q:
        now = q.popleft()

        for next in graph[now]:
            indegree[next] -= 1
            dp[next] = max(dp[next], dp[now] + times[next-1])
            if indegree[next] == 0:
                q.append(next)


    return dp[target]

T = int(input())

for tc in range(T):
    N, K = map(int, input().split())
    times = list(map(int, input().split()))
    graph = defaultdict(list)
    indegree = [0]*(N+1)

    for k in range(K):
        s, e = map(int, input().split())
        graph[s].append(e)
        indegree[e] += 1

    target = int(input())

    print(ACMcraft())