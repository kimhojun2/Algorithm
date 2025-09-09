#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int f_max = 0;
char graph[50][50];
int visited[50];

void bfs(int x)
{
    fill_n(visited,50,0);
    
    queue<pair<int,int>> q;
    q.push({x,1});
    visited[x] = 1; 
    int f_cnt = 0;
    
    while(!q.empty())
    {
        int now_x = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(depth>2) continue; 
        for(int i=0;i<N;i++)
        {
            if(graph[now_x][i] == 'Y' && visited[i] == 0)
            {
                visited[i]=1;
                f_cnt++;
                q.push({i,depth+1});
            }
        }
    }
    if(f_cnt > f_max)
        f_max = f_cnt;
}

int main()
{
    cin>>N;
    
    
    
    for(int i=0;i<N;i++)
    {
         for(int j=0;j<N;j++)
        {
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        bfs(i);
    }
    cout<<f_max;
    return 0;
}