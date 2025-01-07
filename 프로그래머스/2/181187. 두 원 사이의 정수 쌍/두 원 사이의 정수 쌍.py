def solution(r1, r2):
    import math
    answer = 0

    for i in range(1, r2):
        MAX_Y = math.floor(math.sqrt(r2 * r2 - i * i))
        if r1 * r1 > i * i:
            MIN_Y = math.ceil(math.sqrt(r1 * r1 - i * i))
        else:
            MIN_Y = 1

        answer += MAX_Y - MIN_Y + 1

    answer += r2 - r1 + 1
    answer *= 4
    return answer

solution(2,3)