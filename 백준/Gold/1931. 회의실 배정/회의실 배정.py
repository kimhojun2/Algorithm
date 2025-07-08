import sys
input = sys.stdin.readline

N = int(input())

lst = [list(map(int, input().split())) for _ in range(N)]

sorted_lst = sorted(lst, key=lambda x:(x[1],x[0]))


end = sorted_lst[0][1]
cnt = 1
for i in range(1, N):
    now_start, now_end = sorted_lst[i][0], sorted_lst[i][1]

    if now_start >= end:
        cnt += 1
        end = now_end

print(cnt)