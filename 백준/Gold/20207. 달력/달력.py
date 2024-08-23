N = int(input())

sc = []
visited = [0] * 367
last = 0
first = 366
for i in range(N):
    start, end = map(int, input().split())
    sc.append((start, end, end-start + 1))
    if end > last:
        last = end
    if start < first:
        first = start
# print(sc)
# plan = sorted(sc, key=lambda x: (x[0], -x[2]))
# print(plan)
    for j in range(start, end+1):
        visited[j] += 1


# visited[first:last+1]
area = 0
x = 0
y = 1
for v in visited[first:last+2]:
    if v == 0:
        area += (x * y)
        x = 0
        y = 0
        continue

    if v > y:
        y = v
    x += 1

print(area)