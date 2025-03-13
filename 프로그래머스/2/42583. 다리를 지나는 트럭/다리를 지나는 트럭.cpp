#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int now_weight = 0;
    int now_idx = 0;
    queue<pair<int, int>> q;

    while (now_idx < truck_weights.size() || !q.empty()) { 
        if (!q.empty() && q.front().second == answer) { 
            now_weight -= q.front().first;
            q.pop();
        }

        if (now_idx < truck_weights.size()) { 
            int now_truck = truck_weights[now_idx];
            if (now_weight + now_truck <= weight) {
                now_weight += now_truck;
                q.push({now_truck, answer + bridge_length});
                now_idx++;
            }
        }

        answer++;
    }

    return answer;
}
