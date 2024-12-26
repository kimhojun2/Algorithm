def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1])
    n = len(routes)
    camera = -float('inf')
    for route in routes:
        car_in, car_out = route
        if car_in > camera:
            answer+=1
            camera = car_out
    return answer