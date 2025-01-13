def solution(progresses, speeds):
    answer = []
    idx = 0
    day = 1
    cnt = 0
    # for i in range(len(speeds)):
    while idx < len(speeds):
        progress = progresses[idx]
        if progress + day * speeds[idx] >= 100:
            cnt += 1
            idx += 1
            continue

        if cnt == 0:
            day += 1
            continue

        answer.append(cnt)
        cnt = 0

    answer.append(cnt)

    return answer