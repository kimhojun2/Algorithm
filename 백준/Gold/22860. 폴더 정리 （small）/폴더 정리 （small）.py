import sys
input = sys.stdin.readline
N, M = map(int, input().split())
files = {}
for i in range(N+M):
    path = list(map(str, input().rstrip().split()))

    if path[0] not in files:
        if path[2] == '1':
            files[path[0]] = [0, (path[1], path[2])]
        else:
            files[path[0]] = [1, (path[1], path[2])]

    else:
        if path[2] == '1':
            files[path[0]].append((path[1], path[2]))
        else:
            files[path[0]][0] += 1
            files[path[0]].append((path[1], path[2]))


C = int(input())


for c in range(C):
    cnt = 0
    check = list(map(str, input().rstrip().split('/')))
    # print(check)

    q = [check[-1]]
    F = []
    while q:
        name = q.pop()
        if name in files:
            cnt += int(files[name][0])
            for i in range(1, len(files[name])):
                if files[name][i][1] == '1':
                    q.append(files[name][i][0])
                else:
                    F.append(files[name][i][0])
    print(len(set(F)), cnt)

