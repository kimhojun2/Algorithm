def solution(brown, yellow):
    answer = []
    N = brown +yellow
    for i in range(3, N):
        if N%i !=0:
            continue
            
        row = max(i,N//i)
        col = min(i,N//i)
        if (col+row)*2 -4 == brown and (col-2)*(row-2) == yellow:
            return[row,col]
            
