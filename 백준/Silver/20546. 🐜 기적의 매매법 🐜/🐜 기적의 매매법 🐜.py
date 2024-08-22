N = int(input())

BNF_money = N
BNF_ju = 0
TIMING_money = N
TIMING_ju = 0
up = 0
down = 0
chart = list(map(int, input().split()))
yesterday = chart[0]

for i in range(len(chart)):
    today = chart[i]

    # BNP 전략: 매일 최대한 많이 매수
    buying = BNF_money // today
    BNF_money -= buying * today
    BNF_ju += buying

    # TIMING 전략
    if today < yesterday:
        down += 1
        up = 0
        if down >= 3:  # 3일 연속 하락 시 전량 매수
            buy = TIMING_money // today
            TIMING_money -= buy * today
            TIMING_ju += buy
    elif today > yesterday:
        up += 1
        down = 0
        if up >= 3:  # 3일 연속 상승 시 전량 매도
            if TIMING_ju > 0:
                TIMING_money += today * TIMING_ju
                TIMING_ju = 0
    else:
        up = 0
        down = 0
    yesterday = today

# 마지막 날 자산 계산
result1 = TIMING_ju * chart[-1] + TIMING_money
result2 = BNF_ju * chart[-1] + BNF_money
if result1 > result2:
    print('TIMING')
elif result2 > result1:
    print('BNP')
else:
    print('SAMESAME')
