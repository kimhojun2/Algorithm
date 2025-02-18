#include <string>
#include <vector>
using namespace std;

bool binary(int n, int one){
    int one_next=0;
    while(n>0){
        if(n%2==1){
            one_next++;
        }
        n /= 2;
    }
    if(one_next == one){
        return true;
    }
    return false;
}

int solution(int n) {
    int answer = 0;
    int next = n+1;
    int one=0;
    while(n>0){
        if(n%2==1){
            one++;
        }
        n /= 2;
    }
    while(1){
        if(binary(next,one)){
            answer = next;
            break;
        }
        next++;
    }
    
    
    return answer;
}