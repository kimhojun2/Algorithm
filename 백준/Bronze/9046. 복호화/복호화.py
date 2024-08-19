T = int(input())

for tc in range(T):
    cnt = {}
    key = input()

    for i in key:
        if i == ' ':
            continue

        else:
            if i not in cnt:
                cnt[i] = 1
            else:
                cnt[i] += 1

    max_value = max(cnt.values())

    max_keys = [key for key, value in cnt.items() if value == max_value]

    if len(max_keys) == 1:
        print(max_keys[0])
    else:
        print('?')