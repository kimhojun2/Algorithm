import math

G = int(input())

left = 1
right = math.ceil(math.sqrt(G))
ans = []
while left < right:
    now = right*right - left*left
    if now > G:
        left += 1

    elif now < G:
        right += 1

    else:
        ans.append(right)
        right +=1
        left += 1


if ans:
    ans.sort()
    for i in ans:
        print(i)
else:
    print(-1)