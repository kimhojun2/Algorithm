N, M = map(int, input().split())
p = [[] for _ in range(M)]
visited = [0]*M
truth = list(map(int, input().split()))

for i in range(M):
    p[i] = list(map(int, input().split()))

# print(p)

ans = 0
check = True
turn = 1
first = True
while check and turn < len(truth):
    k = len(truth)
    for i in range(turn, len(truth)):
        person = truth[i]
        for j in range(len(p)):
            if not visited[j]:
                if first:
                    ans += 1
                party = p[j]
                if person not in party[1:]:
                    continue
                else:
                    visited[j] = 1
                    ans -= 1
                    for b in party[1:]:
                        if b not in truth[1:]:
                            truth.append(b)
        first = False
    turn  = k
if first:
    print(M)
else:
    print(ans)
