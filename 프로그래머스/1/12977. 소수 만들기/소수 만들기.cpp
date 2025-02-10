#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                int now = nums[i]+nums[j]+nums[k];
                bool tf = true;
                for(int idx=2;idx<=sqrt(now);idx++){
                    if(now%idx==0 && idx != now){
                        tf = false;
                        break;
                    }
                }if(tf) answer++;
            }
        }
    }
    

    return answer;
}