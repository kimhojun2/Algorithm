N = int(input())

ans = 0
total = 0
start = 0
end = 0

while end <= N:
    if total < N:
        end +=1
        total += end

    elif total > N:
        total -= start
        start += 1

    else:
        ans +=1
        end +=1
        total += end

print(ans)