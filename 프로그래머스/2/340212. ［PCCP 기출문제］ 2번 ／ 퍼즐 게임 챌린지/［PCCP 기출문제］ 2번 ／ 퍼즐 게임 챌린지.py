def solution(diffs, times, limit):

    left = 1
    right = max(diffs)

    answer = right
    while left <= right:
        mid = (left + right) // 2

        total_time = 0
        for idx, diff in enumerate(diffs):
            if diff <= mid:
                total_time += times[idx]
            else:
                total_time += (diff-mid) * (times[idx-1] + times[idx]) + times[idx]

            if total_time > limit:
                break

        if total_time > limit:
            left = mid +1
        else:
            right = mid - 1
            answer = min(answer, mid)


    return answer
