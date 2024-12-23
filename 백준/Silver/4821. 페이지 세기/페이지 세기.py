while True:
    limit = int(input())
    total = 0
    check = [False] * 1001
    if limit == 0:
        break
    pages = list(input().split(','))
    for page in pages:
        ps = page.split('-')
        if len(ps) == 2:
            low, high = int(ps[0]),int(ps[1])
            if low > high:
                continue
            for i in range(low,min(high+1,limit+1),1):
                if not check[i]:
                    check[i] = True
                    total += 1
        else:
            if int(page) <= limit:
                if not check[int(page)]:
                    check[int(page)] = True
                    total += 1
    print(total)

