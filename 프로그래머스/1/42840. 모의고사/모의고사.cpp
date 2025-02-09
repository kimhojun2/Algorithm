#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1=0;
    int arr1[5] = {1,2,3,4,5};
    int cnt2=0;
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int cnt3 = 0;
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    for(int i=0;i<answers.size();i++){
        int now = answers[i];
        if(arr1[i%5]==now){
            cnt1++;
        }
        if(arr2[i%8] == now){
            cnt2++;
        }
        if(arr3[i%10]==now){
            cnt3++;
        }
    }
    int M = max(cnt1, max(cnt2,cnt3));
    if(M == cnt1){
        answer.push_back(1);
    }
    if(M==cnt2){
        answer.push_back(2);
    }
    if(M==cnt3){
        answer.push_back(3);
    }
    
    return answer;
}