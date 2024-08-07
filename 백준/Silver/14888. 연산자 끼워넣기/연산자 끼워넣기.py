N = int(input())
numbers = list(map(int, input().split()))
calc = list(map(int, input().split()))

max_value = -1000000001
min_value = 1000000001

def func(index, current_value):
    global max_value, min_value

    if index == N:
        max_value = max(max_value, current_value)
        min_value = min(min_value, current_value)
        return

    if calc[0] > 0:
        calc[0] -= 1
        func(index + 1, current_value + numbers[index])
        calc[0] += 1

    if calc[1] > 0:
        calc[1] -= 1
        func(index + 1, current_value - numbers[index])
        calc[1] += 1

    if calc[2] > 0:
        calc[2] -= 1
        func(index + 1, current_value * numbers[index])
        calc[2] += 1

    if calc[3] > 0:
        calc[3] -= 1
        if current_value < 0:
            func(index + 1, -(-current_value // numbers[index]))
        else:
            func(index + 1, current_value // numbers[index])
        calc[3] += 1

func(1, numbers[0])
print(max_value)
print(min_value)
