N = int(input())
arr = list(map(int, input().split()))

visited = [0] * 100001
left = 0
ans = 0

for right in range(N):
    while visited[arr[right]]:
        visited[arr[left]] = 0
        left += 1
    visited[arr[right]] = 1
    ans += (right - left + 1)

print(ans)
