#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> map(n+1);
    for(int i=0;i<n;i++){
        stack<int> bn;
        int now1 = arr1[i];
        int now2 = arr2[i];
        int cnt = 0;
        while(cnt!=n){
            if(now1%2==1 || now2%2==1){
                bn.push(1);
            }
            else{
               bn.push(0); 
            }
            now1/=2;
            now2/=2;
            cnt++;
        }
        string result = "";
        while(!bn.empty()){
            int t = bn.top();
            if(t == 1){
                result +='#';
            }
            else{
                result += ' ';
            }
            bn.pop();
        }
        answer.push_back(result);
    }
    
    
    return answer;
}