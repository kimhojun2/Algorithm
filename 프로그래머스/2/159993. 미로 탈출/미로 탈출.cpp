#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int ly=-1;
int lx=-1;

int bfs(vector<string>& maps, int i, int j, int v, char target){
    int N = maps.size();
    int M = maps[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    vector<vector<int>>visited(N,vector<int>(M,0));
    visited[i][j] = v;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(maps[y][x] == target){
            ly = y;
            lx = x;
            return visited[y][x];
        }
        
        for(int d=0;d<4;d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(visited[ny][nx] != 0 || maps[ny][nx] == 'X') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    return -1;
}



int solution(vector<string> maps) {
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();
    int NV;
    bool tf = true;
    for(int i=0;i<N;i++){
        if(!tf) break;
        for(int j=0;j<M;j++){
            // cout << maps[i][j]<<" ";
            if(maps[i][j]=='S'){
                NV = bfs(maps,i,j,1,'L');
                tf = false;
                cout <<NV;
                break;
            }            
        }
    }
    if(NV==-1) return -1;
    answer = bfs(maps,ly,lx,NV,'E') -1;
    if(answer==-2) return -1;
    return answer;
}