def solution(bandage, health, attacks):
    answer = health
    max_health = health

    for i in range(len(attacks) - 1):
        attack = attacks[i]
        time, power = attack[0], attack[1]
        answer -= power
        if answer <= 0:
            return -1

        dusthr = attacks[i + 1][0] - time - 1
        if dusthr > 0:
            heal = (dusthr // bandage[0]) * bandage[2] + dusthr * bandage[1]
            answer += heal
            if answer > max_health:
                answer = max_health


    answer -= attacks[-1][1]
    if answer <= 0:
        return -1

 

    return answer
