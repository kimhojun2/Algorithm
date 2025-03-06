#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        vector<int> Score;
        for(int j=0;j<num;j++){
           int score;
           cin>>score;
           Score.push_back(score);
        }

        sort(Score.begin(),Score.end());

        int Max=Score.back();
        int Min=Score.front(); 
        int gap=0;

        for(int j=1;j<num;j++){
            gap=max(gap,Score[j]-Score[j-1]);
        }
        cout<<"Class "<<i+1<<'\n';
        cout<<"Max "<<Max<<", Min "<<Min
        <<", Largest gap "<<gap<<'\n';
    }
    return 0;
}