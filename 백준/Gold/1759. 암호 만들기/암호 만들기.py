L, C = map(int, input().split())
lst = list(input().split())
lst.sort()
check = ['a','e','i','o','u']
visited = [0]*C

ahdma = 0
wkdma = 0
def back(idx, word):
    global ahdma, wkdma

    if len(word) + (C-idx-1) < L: return

    if len(word) == L and ahdma > 0 and wkdma > 1:
        print(word)
        return

    for i in range(idx+1, C):
        now = lst[i]
        if now in check:
            ahdma += 1
            back(i,word+now)
            ahdma -= 1
        else:
            wkdma += 1
            back(i, word+now)
            wkdma -= 1


ans = back(-1, '')
