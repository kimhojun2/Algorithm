#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string score = "";
    vector<char> numbers ={'0','1','2','3','4','5','6','7','8','9'};
    int arr[3] ={0,};
    int cnt =0;
    for(int i=0;i<dartResult.size();i++){
        char now = dartResult[i];
        if (isdigit(now)) {
            score += now;
            continue;
        }
        if(now=='S'){
            arr[cnt] = stoi(score);
            score = "";
            cnt++;
            continue;
        }
        if(now=='D'){
            arr[cnt] = pow(stoi(score),2);
            score = "";
            cnt++;
            continue;
        }
        if(now=='T'){
            arr[cnt] = pow(stoi(score),3);
            score = "";
            cnt++;
            continue;
        }
        if(now=='*'){
            if(cnt==1){
                arr[0] = arr[0]*2;
            }
            else{
                arr[cnt-1] = arr[cnt-1]*2;
                arr[cnt-2] = arr[cnt-2]*2;
            }
        }
        if(now=='#'){
            arr[cnt-1] = -arr[cnt-1];
        }
        
    }
    for(auto i:arr){
        answer+=i;
    }
    return answer;
}