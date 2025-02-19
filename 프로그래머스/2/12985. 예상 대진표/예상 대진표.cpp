#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    int A = a;
    int B = b;
    while(1){
        if(A==B) break;
        A = (A/2) + (A%2);
        B = (B/2) + (B%2);
        answer++;
    }
    
    return answer;
}