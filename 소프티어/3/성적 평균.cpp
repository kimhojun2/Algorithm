#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int main(int argc, char** argv)
{
    int N,K;
    cin >>N>>K;
    vector<int>arr(N);
    vector<int>sum(N);
    for(int i=0;i<N;i++){
        int now;
        if(i==0){
            cin >> now;
            sum[0] = now;
            arr[0] = now;
        }
        else{
            int now;
            cin >>now;
            sum[i] = sum[i-1] + now;
            arr[i] = now;
        }
    }
    for(int i=0;i<K;i++){
        int left, right;
        cin >> left>>right;
        double S = sum[right-1] - sum[left-1]+arr[left-1];
        double D = right-left+1;
        double ans = round(S/D*100)/100;
        cout << fixed << setprecision(2) << ans << '\n';
    }
    
   return 0;
}