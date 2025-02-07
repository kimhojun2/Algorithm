#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    deque<int> dq;
    for(int i : arr){
        if(!dq.empty()){
            if(dq.back()==i){
            continue;
            }
        }
        dq.push_back(i);
    }
    while(!dq.empty()){
        answer.push_back(dq.front());
        dq.pop_front();
    }
    

    return answer;
}