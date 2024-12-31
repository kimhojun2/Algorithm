import sys
from collections import deque

input = sys.stdin.readline

dic = {i: deque(map(int, input().strip())) for i in range(1, 5)}
K = int(input())


for _ in range(K):
    idx, dir = map(int, input().split())
    move = [(idx, dir)]


    cur_dir = dir
    for j in range(idx + 1, 5):
        if dic[j - 1][2] != dic[j][6]:
            cur_dir = -cur_dir
            move.append((j, cur_dir))
        else:
            break


    cur_dir = dir
    for j in range(idx - 1, 0, -1):
        if dic[j][2] != dic[j + 1][6]:
            cur_dir = -cur_dir
            move.append((j, cur_dir))
        else:
            break


    for now, now_dir in move:
        dic[now].rotate(now_dir)

ans = sum((2 ** (i - 1)) for i in range(1, 5) if dic[i][0] == 1)
print(ans)
