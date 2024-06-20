N = int(input())

player_list = {}

for i in range(N):
    player = input()
    first = player[0]
    if first in player_list:
        player_list[first] += 1

    else:
        player_list[first] = 1

filtered_list = {k: v for k, v in player_list.items() if v >= 5}
sorted_list = sorted(filtered_list.keys())

if sorted_list:
    result = ''.join(sorted_list)
    print(result)
else:
    print('PREDAJA')