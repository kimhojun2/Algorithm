#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int bfs(vector<string>& maps, int i, int j){
    int N = maps.size();
    int M = maps[0].size();
    int sum = maps[i][j]-'0';
    maps[i][j] = 'X';
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(maps[ny][nx]=='X') continue;
            sum += (maps[ny][nx]-'0');
            maps[ny][nx] = 'X';
            q.push({ny,nx});
        }
    }
    return sum;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            if(maps[i][j] != 'X'){
                answer.push_back(bfs(maps,i,j));
            }
        }
    }
    if(answer.empty()) return {-1};
    sort(answer.begin(),answer.end());
    return answer;
}