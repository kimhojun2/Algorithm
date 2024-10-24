money = int(input())
stock= list(map(int, input().split()))

wnsgus_money = money
wnsgus_stock = 0
tjdals_money = money
tjdals_stock = 0

cnt_up = 0
cnt_down = 0
for date in range(14):
    wnsgus_today = wnsgus_money // stock[date]
    wnsgus_money -= wnsgus_today * stock[date]
    wnsgus_stock += wnsgus_today

    if date != 0:
        if stock[date] > stock[date-1]:
            cnt_up += 1
            cnt_down = 0
        elif stock[date] < stock[date-1]:
            cnt_down += 1
            cnt_up = 0

        else:
            cnt_down = cnt_up = 0

    if cnt_up >= 3:
        tjdals_money += tjdals_stock * stock[date]
        tjdals_stock = 0

    elif cnt_down >= 3:
        tjdals_today = tjdals_money // stock[date]
        tjdals_money -= tjdals_today * stock[date]
        tjdals_stock += tjdals_today

if wnsgus_money + wnsgus_stock * stock[-1] > tjdals_money + tjdals_stock * stock[-1]:
    print("BNP")

elif wnsgus_money + wnsgus_stock * stock[-1] < tjdals_money + tjdals_stock * stock[-1]:
    print("TIMING")
else:
    print("SAMESAME")

