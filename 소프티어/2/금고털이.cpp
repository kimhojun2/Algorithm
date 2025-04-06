#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>& A, pair<int,int>& B){
    return A.second > B.second;
}

int main(int argc, char** argv)
{
    int W, N;
    cin >>W >>N;
    vector<pair<int,int>>arr;
    for(int i=0;i<N;i++){
        int M, P;
        cin >>M>>P;
        arr.push_back({M,P});
    }
    sort(arr.begin(), arr.end(), compare);

    int answer = 0;

    for(int i=0;i<N;i++){
        if(W<=0) break;
        int m = arr[i].first;
        int v = arr[i].second;
        int w = min(m,W);
        answer += w*v;
        W -= w;
    }

    cout << answer;
    
   return 0;
}