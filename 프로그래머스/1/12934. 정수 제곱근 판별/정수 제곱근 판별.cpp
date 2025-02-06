#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long now = sqrt(n);
    if(now*now==n){
        answer = (now+1)*(now+1);
    }else{
        answer = -1;
    }
    return answer;
}