#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int>& A, vector<int>& B){
    return A[1] < B[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), compare);

    int edge = targets[0][1];
    for(int i=1;i<targets.size();i++){
        int start = targets[i][0];
        int end = targets[i][1];
        if(start<edge) continue;
        edge = end;
        answer++;
    }
    return answer;
}