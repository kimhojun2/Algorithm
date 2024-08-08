L, C = map(int, input().split())

arr = list(input().split())
a = ['a', 'e', 'i', 'o', 'u']
visited = [0] * C
ans = []
realans = []
def letter(level, mo, ja):
    if level == L:
        if mo >= 1 and ja >= 2:
            real = ''.join(ans)
            realans.append(real)
            return

    for i in range(C):
        if not visited[i]:
            if arr[i] in a:
                if ans:
                    if ans[-1] > arr[i]:
                        continue

                visited[i] = 1
                ans.append(arr[i])
                letter(level + 1, mo+1, ja)
                visited[i] = 0
                ans.pop()


            else:
                if ans:
                    if ans[-1] > arr[i]:
                        continue
                visited[i] = 1
                ans.append(arr[i])
                letter(level+1, mo, ja+1)
                visited[i] = 0
                ans.pop()

letter(0,0,0)
box = sorted(realans)

for b in box:
    print(b)