#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max_num = max(n,m);
    int min_num = min(n,m);
    int min_ans=0;
    for(int i=1;i<=min_num;i++){
        if(n%i==0&&m%i==0){
            if(i>min_ans){
                min_ans = i;
            }
            
        }
    }
    answer.push_back(min_ans);
    answer.push_back((min_ans*(n/min_ans)*(m/min_ans)));
    
    return answer;
}