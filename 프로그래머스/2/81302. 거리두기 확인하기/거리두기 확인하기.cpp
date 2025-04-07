#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> answer;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

bool bfs(vector<string>& place, vector<pair<int,int>>& ps, int idx){
    int visited[5][5] ={0,};
    queue<pair<int,int>>q;
    q.push(ps[idx]);
    visited[ps[idx].first][ps[idx].second] = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny = y +dy[d];
            int nx = x +dx[d];
            if(ny<0||nx<0||ny>=5||nx>=5) continue;
            // if(ny<=ps[idx].first && nx<=ps[idx].second) continue;
            if(visited[ny][nx] != 0) continue;
            if(place[ny][nx] == 'P' && visited[ny][nx] <=3) return false;
            if(place[ny][nx] == 'X') continue;
            if(visited[y][x] + 1 >= 3) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    return true;
}


void check(vector<string>& place){
    vector<pair<int,int>>ps;
    int cnt = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){            
            if(place[i][j] == 'P'){
                cnt++;
                ps.push_back({i,j});
            }
        }
    }
    for(int i=0;i<cnt;i++){
        bool tf = bfs(place, ps, i);
        if(!tf){
            answer.push_back(0);
            return;
        }
    }
    answer.push_back(1);
}


vector<int> solution(vector<vector<string>> places) {
    for(int i=0;i<places.size();i++){
        check(places[i]);
    }
    return answer;
}