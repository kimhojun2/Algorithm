import sys
from collections import deque
input = sys.stdin.readline
N, K = map(int, input().split())
arr = list(map(int, input().split()))
box = deque(arr)
robot = deque([False] * N)
'''
1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
3. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
4. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
5. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
'''
ans = 0
def move():
    global ans
    # 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    box.rotate(1)
    robot.rotate(1)
    robot[N-1] = False

    # 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
    for j in range(N-2,-1,-1):
        # 3. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        if robot[j] and not robot[j+1] and box[j+1] > 0:
            robot[j] = False
            robot[j+1] = True
            # 로봇이 어떤 칸으로 이동하면 그 칸의 내구도는 즉시 1만큼 감소한다.
            box[j+1] -= 1
            if box[j+1] == 0:
                ans += 1
    if robot[N-1]:
        robot[N-1] = False


    #4. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
    if box[0] > 0:
        robot[0] = True
        box[0] -= 1
        if box[0] == 0:
            ans += 1


# 5. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
C = 0
while ans < K:
    move()
    C += 1


print(C)