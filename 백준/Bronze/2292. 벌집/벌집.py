N = int(input())
idx = 1

if N == 1:
    print(1)
else:
    range_end = 1

    while range_end < N:
        range_end += 6 * idx
        idx += 1

    print(idx)
