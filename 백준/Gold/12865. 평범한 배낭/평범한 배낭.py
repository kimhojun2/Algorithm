N, K = map(int, input().split())
dp = [0] * (K+1)
things = []
for i in range(N):
    W, V = map(int, input().split())
    things.append((W,V))
for thing in things:
    w, v = thing

    for i in range(K, w-1, -1):
        dp[i] = max(dp[i], dp[i-w] + v)

print(dp[-1])