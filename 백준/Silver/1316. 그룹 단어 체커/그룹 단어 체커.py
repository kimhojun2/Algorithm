T = int(input())

ans = 0
for tc in range(T):
    word = input()
    L = len(word)
    if L == 1:
        ans += 1
    check = []
    last = ''
    for l in range(L):
        now = word[l]
        if l == 0:
            last = now

        elif l == L-1:
            if now not in check:
                ans += 1

        else:
            if now not in check and now == last:
                continue

            elif now not in check and now != last:
                check.append(last)
                last = now

            else:
                break

print(ans)