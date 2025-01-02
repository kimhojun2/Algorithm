def solution(n):
    answer = 0
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + i
    left = 0
    right = 1

    while left < right and right<=n:
        now = dp[right] - dp[left]
        if now == n:
            answer += 1
            right +=1
            left += 1

        elif now > n:
            left += 1

        else:
            right += 1

    return answer