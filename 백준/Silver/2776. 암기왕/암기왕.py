T = int(input())
for _ in range(T):
    N = int(input())
    ans = sorted(map(int, input().split()))  # 정렬된 리스트 생성
    M = int(input())
    arr = list(map(int, input().split()))

    for i in arr:
        left = 0
        right = N - 1
        found = False

        while left <= right:
            mid = (left + right) // 2

            if ans[mid] == i:  # i를 찾으면 1을 출력하고 종료
                found = True
                break
            elif ans[mid] < i:
                left = mid + 1
            else:
                right = mid - 1

        if found:
            print(1)
        else:
            print(0)
