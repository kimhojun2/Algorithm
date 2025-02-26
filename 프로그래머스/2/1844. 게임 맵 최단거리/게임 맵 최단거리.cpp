#include<vector>
#include<queue>
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};


int bfs(int N, int M, vector<vector<int>> &maps){
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<int>> visited(N,vector<int>(M,0));
    visited[0][0] = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4;d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny<0 || nx<0 || ny>=N || nx>=M || maps[ny][nx] == 0 || visited[ny][nx] !=0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    return visited[N-1][M-1];
}


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    answer = bfs(maps.size(), maps[0].size(), maps);
    if(answer==0){
        return -1;
    }
    return answer;
}