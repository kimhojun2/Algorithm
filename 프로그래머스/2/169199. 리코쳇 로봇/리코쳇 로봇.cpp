#include <string>
#include <vector>
#include <queue>
#include <iostream>

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

using namespace std;

int visited[100][100] = {0,};

int bfs(vector<string>& board,int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    visited[i][j] = 1;
    int N = board.size();
    int M = board[0].size();
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int k = 1;
            int ny = y;
            int nx = x;
            while(1){
                ny += dy[d];
                nx += dx[d];
                if(ny<0||nx<0||ny>=N||nx>=M||board[ny][nx] == 'D'){
                    ny -= dy[d];
                    nx -= dx[d];
                    break;
                }
            }
            if(board[ny][nx] == 'G') return visited[y][x];
            
            if(visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    return -1;
}


int solution(vector<string> board) {
    int answer = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j] == 'R')
                answer = bfs(board,i,j);
        }
    }
    return answer;
}