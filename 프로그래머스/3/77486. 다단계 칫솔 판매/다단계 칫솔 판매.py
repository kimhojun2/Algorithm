def rule(incomes, dic, name, income):
    if income // 10 == 0:
        incomes[name] += income
        return
    
    incomes[name] += (income - (income//10))
    if dic[name] == "-":
        return
    rule(incomes, dic, dic[name], income//10)
    
    return

def solution(enroll, referral, seller, amount):
    answer = []
    dic = {}
    L = len(enroll)
    S = len(seller)
    incomes = {}
    for i in range(L):
        dic[enroll[i]] = referral[i]
        incomes[enroll[i]] = 0
    
    for i in range(S):
        rule(incomes, dic, seller[i], 100*amount[i])
    
    for ans in incomes.values():
        answer.append(ans)
    
    return answer
