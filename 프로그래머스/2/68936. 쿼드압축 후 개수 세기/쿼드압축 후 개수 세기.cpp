#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt_zero = 0;
int cnt_one = 0;

void check(int y, int x, int s, vector<vector<int>>& arr){
    int now = arr[y][x];
    for(int i=y;i<y+s;i++){
        for(int j=x;j<x+s;j++){
            if(arr[i][j] != now){
                // cout << y <<" "<<x<<'\n';
                check(y,x,s/2,arr);
                
                // cout << y+s/2 <<" "<<x<<'\n';
                check(y+s/2,x,s/2,arr);
                
                // cout << y <<" "<<x+s/2<<'\n';
                check(y,x+s/2,s/2,arr);
                
                // cout << y+s/2 <<" "<<x+s/2<<'\n';
                check(y+s/2,x+s/2,s/2,arr);
                return;
            }
        }
    }
    if (now == 1) cnt_one++;
    else cnt_zero++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    check(0,0,arr.size(),arr);
    answer = {cnt_zero, cnt_one};
    return answer;
}