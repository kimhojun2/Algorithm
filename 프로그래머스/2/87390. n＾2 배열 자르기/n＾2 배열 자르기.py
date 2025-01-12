def solution(n, left, right):
    answer = []
    R = left // n
    C = left % n

    while left <= right:

        answer.append(max(R, C) + 1)

        C += 1

        if C == n:
            C = 0
            R += 1

        left += 1

    return answer