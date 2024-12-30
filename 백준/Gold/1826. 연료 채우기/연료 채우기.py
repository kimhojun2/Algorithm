import heapq

N = int(input())
stations = [list(map(int, input().split())) for _ in range(N)]
end, oil = map(int, input().split())

def solve(end, oil):
    stations.append([end, 0])
    stations.sort()

    max_heap = []
    current_fuel = oil
    current_position = 0
    refuels = 0

    for position, fuel in stations:
        distance_to_next = position - current_position

        while current_fuel < distance_to_next:
            if not max_heap:
                return -1
            current_fuel += -heapq.heappop(max_heap)
            refuels += 1

        current_fuel -= distance_to_next
        current_position = position
        heapq.heappush(max_heap, -fuel)

    return refuels


print(solve(end,oil))