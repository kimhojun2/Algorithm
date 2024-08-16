def solution(h1, m1, s1, h2, m2, s2):
    answer = 0

    time1 = h1 * 3600 + m1 * 60 + s1
    time2 = h2 * 3600 + m2 * 60 + s2  

    if time1 == 0 * 3600 or time1 == 12 * 3600:
        answer += 1
    # 초침    6도
    # 분침    0.1도
    # 시침    1/120도
    # 최대    86400번
    while time1 < time2:
        now_h = time1 / 120 % 360
        now_m = time1 / 10 % 360
        now_s = time1 * 6 % 360

        next_time1 = time1 + 1
        
        next_h = next_time1 / 120 % 360
        if next_h == 0:
            next_h = 360

        next_m = next_time1 / 10 % 360
        if next_m == 0:
            next_m = 360

        next_s = next_time1 * 6 % 360
        if next_s == 0:
            next_s = 360

        if now_s < now_h and next_s >= next_h:
            answer += 1

        if now_s < now_m and next_s >= next_m:
            answer += 1

        if next_s == next_h and next_s == next_m:
            answer -= 1

        time1 += 1
    
    return answer
