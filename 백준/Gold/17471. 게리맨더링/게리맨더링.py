from itertools import combinations
from collections import deque

def select(votes):
    start = votes[0]
    q = deque([start])
    visited = [0] * (N+1)
    visited[start] = 1
    cnt = 1
    total_people = 0

    while q:
        now = q.popleft()
        total_people += people_num[now-1]
        for next in lst[now]:
            if visited[next] == 0 and next in votes:
                q.append(next)
                visited[next] = 1
                cnt += 1

    return cnt, total_people




N = int(input())
people_num = list(map(int, input().split()))
result = float('inf')
lst = [[]for _ in range(N+1)]

for i in range(1, N+1):
    near_node = list(map(int, input().split()))
    for j in range(1, near_node[0] + 1):
        lst[i].append(near_node[j])


for i in range(1, N//2 + 1):
    combis = list(combinations(range(1, N+1), i))
    for combi in combis:
        cnt1, total1 = select(combi)
        cnt2, total2 = select([i for i in range(1, N+1) if i not in combi])
        if cnt1 + cnt2 == N:
            result = min(result, abs(total1-total2))


if result == float('inf'):
    print(-1)
else:
    print(result)
