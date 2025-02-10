#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int small_y=51;
    int large_y=0;
    int small_x=51;
    int large_x=0;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j]=='#'){
                cout << i<<" "<<j;
                if(i<small_y){
                    small_y = i;
                }
                if(i+1>large_y){
                    large_y = i+1;
                }
                if(j<small_x){
                    small_x = j;
                }
                if(j+1>large_x){
                    large_x = j+1;
                }
            }
        }
    }
    answer = {small_y, small_x, large_y,large_x};
    return answer;
}