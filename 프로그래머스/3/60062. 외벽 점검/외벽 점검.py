def solution(n, weak, dist):
    from itertools import permutations
    length = len(weak)
    weak = weak + [w + n for w in weak]
    answer = len(dist) + 1

    for friends in permutations(dist):
        for start in range(length):
            count = 1 
            position = weak[start] + friends[count - 1]
            for index in range(start, start + length):
                if weak[index] > position:
                    count += 1
                    if count > len(dist):
                        break
                    position = weak[index] + friends[count - 1]
            answer = min(answer, count)

    return answer if answer <= len(dist) else -1