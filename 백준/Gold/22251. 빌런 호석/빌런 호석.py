import sys
input = sys.stdin.readline

SEGMENTS = [
    0b1110111,  # 0
    0b0010010,  # 1
    0b1011101,  # 2
    0b1011011,  # 3
    0b0111010,  # 4
    0b1101011,  # 5
    0b1101111,  # 6
    0b1010010,  # 7
    0b1111111,  # 8
    0b1111011   # 9
]

def count_diff(a, b):
    return bin(a ^ b).count('1')

N, K, P, X = map(int, input().split())

current_digits = list(map(int, str(X).zfill(K)))
current_bits = [SEGMENTS[d] for d in current_digits]
answer = 0

for num in range(1, N + 1):
    if num == X:
        continue

    target_digits = list(map(int, str(num).zfill(K)))
    target_bits = [SEGMENTS[d] for d in target_digits]

    total_flip = 0
    for cur, tgt in zip(current_bits, target_bits):
        total_flip += count_diff(cur, tgt)

        if total_flip > P:
            break

    if 1 <= total_flip <= P:
        answer += 1

print(answer)
