#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> answer;
vector<string> path;
vector<bool> used;
int N = 0;

void dfs(string from, vector<vector<string>>& tickets, int count) {
    path.push_back(from);

    if (count == N) {
        answer = path;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i] && tickets[i][0] == from) {
            used[i] = true;
            dfs(tickets[i][1], tickets, count + 1);
            if (!answer.empty()) return;
            used[i] = false;
        }
    }

    path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    N = tickets.size();
    used.resize(N, false);
    dfs("ICN", tickets, 0);
    return answer;
}
