l = input()
cnt = 0
ans = ''

for i in l:
    if i == 'X':
        cnt += 1

    else:
        if cnt % 2 != 0:
            print(-1)
            exit()

        ans += 'AAAA' * (cnt//4)
        cnt %= 4
        ans += 'BB' *(cnt//2)
        cnt = 0
        ans += '.'

if cnt > 0:
    if cnt%2 != 0:
        print(-1)
    else:
        ans += 'AAAA' * (cnt // 4)
        cnt %= 4
        ans += 'BB' * (cnt // 2)

        print(ans)

else:
    print(ans)