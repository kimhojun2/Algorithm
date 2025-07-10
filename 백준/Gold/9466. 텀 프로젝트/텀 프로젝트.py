import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def make_team(now):
    global teams
    visited[now] = 1
    team.append(now)
    np = lst[now]

    if visited[np] == 1:
        if np in team:
            idx = team.index(np)
            teams += len(team[idx:])

    else:
        make_team(np)



T = int(input())
for tc in range(T):
    teams = 0
    n = int(input())
    lst = [0] + list(map(int, input().split()))
    visited = [0]*(n+1)
    for i in range(1,n+1):
        if visited[i] == 0:
            team = []
            make_team(i)

    print(n - teams)