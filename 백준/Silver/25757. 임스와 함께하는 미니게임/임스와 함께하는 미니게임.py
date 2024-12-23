games = {'Y':2,'F':3,'O':4}

N, G = input().split()
data = {}
limit = games[G]
people = 1
ans = 0
for i in range(int(N)):
    now = input()
    if now in data:
        continue
    data[now] = True
    people += 1
    if people == limit:
        ans += 1
        people = 1

print(ans)