#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int idx = 0;
    int Y = 0;
    if(n%w==0){
        Y = n/w;
    }
    else{
        Y = n/w + 1;
    }
    vector<vector<int>>arr(Y,vector<int>(w,0));
    int cnt =1;
    int start_y = 0;
    int start_x = 0;
    for(int y=0;y<Y;y++){
        if(idx%2==0){
            for(int x=0;x<w;x++){
                arr[y][x] = cnt;
                if(cnt == num){
                    start_y = y;
                    start_x = x;
                }
                cnt++;
            }
        }
        else{
            for(int x=w-1;x>=0;x--){
                arr[y][x] = cnt;
                if(cnt == num){
                    start_y = y;
                    start_x = x;
                }
                cnt++;
            }
        }
        idx++;
    }

    for(int i=start_y;i<Y;i++){
        if(arr[i][start_x]<=n) answer++;
    }
    
    
    return answer;
}