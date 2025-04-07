#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long find(long long n){
    long long max = 1;
    
    for(long long i=2;i*i<=n;i++){
        if(n%i == 0){
            max = i;
            if(n/i <= 10000000){
                max = n/i;
                break;
            }
        }
    }  
    return max;
}


vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long i=begin;i<=end;i++){
        if(i==1){
            answer.push_back(0);
            continue;
        }
        answer.push_back(find(i));
        
    }
    return answer;
}