def solution(A, B):
    A.sort()
    B.sort()

    a_pointer = 0
    b_pointer = 0
    score = 0

    while b_pointer < len(B):
        if B[b_pointer] > A[a_pointer]:
            score += 1
            a_pointer += 1
        b_pointer += 1

    return score
