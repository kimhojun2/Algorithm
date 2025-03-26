#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& A, vector<int>& B){
    return A[1] < B[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), compare);

    int camera = -30001; 
    for (auto& route : routes) {
        if (camera < route[0]) { 
            camera = route[1];   
            answer++;
        }
    }
    return answer;
}