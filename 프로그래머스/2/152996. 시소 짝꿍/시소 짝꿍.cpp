#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int seesaw[3] = {2,3,4};

bool check(int A, int B){
    int A_idx = 0;
    int B_idx = 0;
    while(A_idx<3 && B_idx<3){
        A *= seesaw[A_idx];
        B *= seesaw[B_idx];
        if(A==B) return true;
        if(A>B){
            A /= seesaw[A_idx];
            B /= seesaw[B_idx];
            B_idx++;
        }
        else if(A<B){
            A /= seesaw[A_idx];
            B /= seesaw[B_idx];
            A_idx++;
        }
    }
    
    return false;
}


long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    for(int i =0;i<weights.size();i++){
        for(int j=i+1;j<weights.size();j++){
            if(weights[i]*4< weights[j]*2) break;
            if(weights[i]*4==weights[j]*2){
                answer++;
                continue;
            }
            if(weights[i]*4==weights[j]*3){
                answer++;
                continue;
            }
            if(weights[i]*2==weights[j]*2){
                answer++;
                continue;
            }
            if(weights[i]*3==weights[j]*2){
                answer++;
                continue;
            }
        }
    }
    
    return answer;
}