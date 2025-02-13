#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> rank = {6,6,5,4,3,2,1};
        
    int correct = 0;
    int zero = 0;
    for(int i=0;i<6;i++){
        if(lottos[i]==0){
            zero++;
            continue;
        }
        if(count(win_nums.begin(),win_nums.end(),lottos[i]) >0){
            correct++;
        }
    }
    answer = {rank[correct+zero],rank[correct]};
    
    return answer;
}