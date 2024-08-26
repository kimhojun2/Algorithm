from collections import deque

A, B = map(int, input().split())
visited = {}
q = deque()
q.append(A)
visited[A] = 0

while q:
    now = q.popleft()

    if now == B:
        break
    for i in range(2):
        if i == 0:
            after = 2 * now
            if after <= B:
                if after not in visited:
                    visited[after] = visited[now] + 1
                    q.append(after)

        else:
            after = int(str(now) + '1')
            if after <= B:
                if after not in visited:
                    visited[after] = visited[now] + 1
                    q.append(after)

if B not in visited:
    print(-1)
else:
    print(visited[B]+1)