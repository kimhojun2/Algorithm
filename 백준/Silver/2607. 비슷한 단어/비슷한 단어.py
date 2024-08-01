import sys
import copy

input = sys.stdin.readline

N = int(input())

standard = {}
l = 0
cnt = 0
for i in range(N):
    word = input().rstrip()
    if i == 0:
        l = len(word)
        for a in word:
            if a in standard:
                standard[a] += 1
            else:
                standard[a] = 1
    else:
        standard2 = copy.deepcopy(standard)  # 이 부분을 첫 번째 단어 이후로 이동
        if l - 1 <= len(word) <= l + 1:
            error = 0
            for a in word:
                if a in standard2 and standard2[a] > 0:
                    standard2[a] -= 1
                else:
                    error += 1
                    if error > 1:  # error가 1을 초과하면 더 이상 비교하지 않음
                        break
            
            if error <= 1:
                remaining_values = sum(standard2.values())
                if remaining_values <= 1:  # 수정: 남은 문자 개수가 1 이하일 때
                    cnt += 1
print(cnt)
