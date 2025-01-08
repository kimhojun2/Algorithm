def solution(n, words):
    answer = [0,0]
    dic = {}
    cnt = [0] * n
    last = ''
    for idx, word in enumerate(words):
        cnt[idx % n] += 1
        if idx == 0:
            dic[word] = True
            last = word[-1]
            continue

        if last != word[0]:
            answer = [idx % n + 1, cnt[idx % n]]
            return answer

        if word in dic:
            answer = [idx % n + 1, cnt[idx % n]]
            return answer

        else:
            dic[word] = True
            last = word[-1]

    return answer