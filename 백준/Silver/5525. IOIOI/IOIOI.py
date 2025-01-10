# import sys
#
# input = sys.stdin.readline
#
# N = int(input())
# M = int(input())
# word = input()
#
# pattern = 'IOI'
# for n in range(1,N):
#     pattern +='OI'
#
# def kmp_table(pattern):
#     lp = len(pattern)
#     table = [0]*lp
#
#     pidx = 0
#     for idx in range(1,lp):
#         while pidx > 0 and pattern[pidx] != pattern[idx]:
#             pidx = table[pidx-1]
#
#         if pattern[idx] == pattern[pidx]:
#             pidx += 1
#             table[idx] = pidx
#
#     return table
#
#
# def kmp(word, pattern):
#     table = kmp_table(pattern)
#     # result = []
#     cnt = 0
#     pidx = 0
#     for idx in range(len(word)):
#         while pidx>0 and word[idx] != pattern[pidx]:
#             pidx = table[pidx-1]
#
#         if word[idx] == pattern[pidx]:
#             if pidx == len(pattern) -1:
#                 # result.append(idx-len(pattern)+1)
#                 cnt += 1
#                 pidx = table[pidx]
#             else:
#                 pidx +=1
#
#     return cnt
#
# ans = kmp(word, pattern)
# print(ans)


import sys

input = sys.stdin.readline

N = int(input())
M = int(input())
word = input().strip()

count = 0
i = 0
current_pattern_length = 0

while i < M - 1:

    if word[i:i+3] == "IOI":
        current_pattern_length += 1
        i += 2
        if current_pattern_length >= N:
            count += 1
    else:
        current_pattern_length = 0
        i += 1

print(count)
