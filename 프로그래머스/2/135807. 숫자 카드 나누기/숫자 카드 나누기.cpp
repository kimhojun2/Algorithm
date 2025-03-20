#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    int A=0;
    int B=0;
    for(int i=2;i<=arrayA[0];i++){
        bool tf = true;
        for(int AA : arrayA){
            if(AA%i != 0){
                tf = false;
                break;
            }
        }
        if(tf) A = i;
    }
    for(int i=2;i<=arrayB[0];i++){
        bool tf = true;
        for(int BB : arrayB){
            if(BB%i != 0){
                tf = false;
                break;
            }
        }
        if(tf) B = i;
    }
    cout << A<<" "<<B;
    
    if(B!=0){
    for(int now : arrayA){
        if(now % B==0){
            B = 0;
            break;
        }
    }    
    }
    if(A!=0){
    for(int now : arrayB){
        if(now % A ==0){
            A = 0;
            break;
        }
    }
    }
    
    answer = max(A,B);
    
    return answer;
}