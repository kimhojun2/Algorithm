#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long N, start_idx=1, end_idx=1, sum=1;
    int cnt=0;
    cin >> N;
    
    while (end_idx<N+1){
        if(sum<N){
            end_idx++;
            sum = sum+end_idx;
        }
        else if (sum>N){
            sum = sum-start_idx;
            start_idx++;
        }
        else if (sum==N){
            cnt++;
            end_idx++;
            sum = sum+end_idx;
        }
    }
    
    cout << cnt;
    return 0;
}