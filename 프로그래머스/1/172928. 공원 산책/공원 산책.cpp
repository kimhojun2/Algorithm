#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int y,x;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[0].size();j++){
            if(park[i][j] == 'S'){
                y = i;
                x = j;
                break;
            }
        }
    }
    for(auto route : routes){
        char op = route[0];
        int n = route[2] - '0';
        if(op=='N'){
            if(y-n<0) continue;
            int ny;
            for(int k=1;k<=n;k++){
                ny = y-k;
                if(park[ny][x]=='X'){
                    ny = y;
                    break;
                }
            }y = ny;
        }
        else if(op=='S'){
            if(y+n>=park.size()) continue;
            int ny;
            for(int k=1;k<=n;k++){
                ny = y+k;
                if(park[ny][x]=='X'){
                    ny = y;
                    break;
                }
            }y = ny;
        }
        else if(op=='W'){
            if(x-n<0) continue;
            int nx;
            for(int k=1;k<=n;k++){
                nx = x-k;
                if(park[y][nx]=='X'){
                    nx = x;
                    break;
                }
            }x = nx;
        }
        else{
            if(x+n>=park[0].size()) continue;
            int nx;
            for(int k=1;k<=n;k++){
                nx = x+k;
                if(park[y][nx]=='X'){
                    nx = x;
                    break;
                }
            }x = nx;
        }
    }
    answer = {y,x};
    return answer;
}