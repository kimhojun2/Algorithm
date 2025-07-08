import sys
input = sys.stdin.readline

N = int(input())

lst = list(map(int, input().split()))
new_lst = []
ans = [0]*N

for idx, num in enumerate(lst):
    new_lst.append((num,idx))


new_lst.sort()
latest_value = -1e9
latest_idx = 0
next_idx = 0
for now in new_lst:
    value = now[0]
    before_idx = now[1]

    if value > latest_value:
        ans[before_idx] = next_idx
        latest_idx = next_idx
        next_idx += 1
        latest_value = value
    else:
        ans[before_idx] = latest_idx

print(*ans)