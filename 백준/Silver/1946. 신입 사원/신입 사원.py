import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    rank = [list(map(int, input().split())) for _ in range(N)]
    rank_lst = sorted(rank)
    top = 0
    result = 1
    
    for i in range(1, len(rank_lst)):
        if rank_lst[i][1] < rank_lst[top][1]:
            top = i
            result += 1
    
    print(result)