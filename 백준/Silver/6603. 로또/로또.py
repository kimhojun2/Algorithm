def make(level, now):
    if level == 6:
        print(*ans)
        return

    for i in range(now, s):  
        ans.append(numbers[i])
        make(level+1, i+1)  
        ans.pop() 

while True:
    numbers = list(map(int, input().split()))
    s = numbers[0]
    if s == 0:
        break
    numbers = numbers[1:]
    ans = []
    make(0, 0)
    print()
