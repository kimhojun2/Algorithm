from collections import deque

def to_minutes(time_str):
    h, m = map(int, time_str.split(':'))
    return h * 60 + m

def to_time_string(minutes):
    h = minutes // 60
    m = minutes % 60
    return f"{h:02d}:{m:02d}"

def solution(n, t, m, timetable):
    crew = sorted([to_minutes(time) for time in timetable])
    crew = deque(crew)

    bus_time = 540
    for i in range(n):
        count = 0
        last_boarded = 0

        while crew and crew[0] <= bus_time and count < m:
            last_boarded = crew.popleft()
            count += 1

        if i == n - 1:
            if count < m:
                return to_time_string(bus_time)
            else:
                return to_time_string(last_boarded - 1)

        bus_time += t
