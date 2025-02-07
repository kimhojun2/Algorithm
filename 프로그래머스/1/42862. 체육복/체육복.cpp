#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    vector<int> l;
    for(int i : lost){
        auto it = find(reserve.begin(),reserve.end(),i);
        if(it != reserve.end()){
            reserve.erase(it);
        }
        else{
            l.push_back(i);
        }
    }
    
    for(int i : l){
        auto it = find(reserve.begin(),reserve.end(),i-1);
        if(it != reserve.end()){
            reserve.erase(it);
            answer++;
            continue;
        }
        it = find(reserve.begin(),reserve.end(),i+1);
        if(it != reserve.end()){
            reserve.erase(it);
            answer++;
        }
    }
    answer += (n-l.size());
    
    return answer;
}