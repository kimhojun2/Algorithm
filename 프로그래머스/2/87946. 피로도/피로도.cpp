#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(int remain, vector<int> &visited, vector<vector<int>> &dungeons, int count) {
    answer = max(answer, count);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && remain >= dungeons[i][0]) {
            visited[i] = 1;
            dfs(remain - dungeons[i][1], visited, dungeons, count + 1);
            visited[i] = 0; 
        }
    }
}

// bool compare(const vector<int> &a, const vector<int> &b) {
//     if(a[0]==b[0]){
//         return a[1] < b[1];
//     }
//     return a[0] > b[0];
// }


int solution(int k, vector<vector<int>> dungeons) {
    
    vector<int> visited(dungeons.size(), 0);
    // sort(dungeons.begin(),dungeons.end(), compare);
    for (int i = 0; i < dungeons.size(); i++) {
        if (k >= dungeons[i][0]) {
            visited[i] = 1;
            dfs(k - dungeons[i][1], visited, dungeons, 1);
            visited[i] = 0;
        }
    }
    return answer;
}