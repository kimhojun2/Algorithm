import sys
from collections import defaultdict

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    word = input().rstrip()
    condition = int(input())

    positions = defaultdict(list)

    for i, ch in enumerate(word):
        positions[ch].append(i)

    min_len, max_len = float('inf'), 0
    for key in positions:
        if len(positions[key]) >= condition:
            for i in range(len(positions[key]) - condition + 1):
                length = positions[key][i + condition - 1] - positions[key][i] + 1
                min_len = min(min_len, length)
                max_len = max(max_len, length)

    if min_len == float('inf') or max_len == 0:
        print(-1)
    else:
        print(min_len, max_len)