#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    double failRateA = (a.second.second == 0) ? 0 : (double)a.second.first / a.second.second;
    double failRateB = (b.second.second == 0) ? 0 : (double)b.second.first / b.second.second;
    
    if (failRateA == failRateB) {
        return a.first < b.first;
    }
    return failRateA > failRateB;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, pair<int, int>>> rank;
    vector<int> stageCount(N + 2, 0);
    
    for (int stage : stages) {
        stageCount[stage]++;
    }
    
    int remainingPlayers = stages.size();
    
    for (int i = 1; i <= N; i++) {
        if (remainingPlayers == 0) {
            rank.push_back({i, {0, 1}});
        } else {
            rank.push_back({i, {stageCount[i], remainingPlayers}});
        }
        remainingPlayers -= stageCount[i];
    }
    
    sort(rank.begin(), rank.end(), compare);
    
    for (auto &r : rank) {
        answer.push_back(r.first);
    }
    
    return answer;
}
