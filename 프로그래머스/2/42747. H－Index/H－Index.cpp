#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater());

    for(int i =0; i<citations.size();i++){
        int now = citations[i];
        if(now>=i+1){
            answer = i+1;
        }
    }
    return answer;
}