N, X = map(int, input().split())

limits = list(map(int, input().split()))

idx = 0
while True:
    if X + idx> limits[idx%N]:
        print(idx%N+1)
        break
    idx += 1