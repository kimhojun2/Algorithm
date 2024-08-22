T = int(input())
for tc in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    cnt = {}
    for i in range(N):
        now = arr[i]
        if now not in cnt:
            cnt[now] = 1
        else:
            cnt[now] += 1

    out = {}
    for key, value in cnt.items():
        if value < 6:
            out[key] = 1

    scores = {}
    idx = 1
    for i in range(N):
        team = arr[i]
        if team not in out:
            if team in scores:
                if scores[team][0] < 4:
                    scores[team][0] += 1
                    scores[team][1] += idx
                elif scores[team][0] == 4:
                    scores[team][0] += 1
                    scores[team][2] = idx

            else:
                scores[team] = [1, idx, 0]

            idx += 1

    rank = sorted(scores.items(), key=lambda x: (x[1][1], x[1][2]))
    print(rank[0][0])