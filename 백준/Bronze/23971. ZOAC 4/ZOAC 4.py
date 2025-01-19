H, W, N, M = map(int, input().split())
row = (1+(H-1)//(N+1))
col = (1+(W-1)//(M+1))
print(row*col)