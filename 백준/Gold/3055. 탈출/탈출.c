#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 50

int R, C;
char map_[MAX][MAX];
int sy, sx;

int wy[MAX*MAX][2], wfront=0, wrear=0;
int hy[MAX*MAX][2], hfront=0, hrear=0;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

int bfs(){
    int dist[MAX][MAX];
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) dist[i][j]=-1;
    dist[sy][sx]=0;

    while(hfront<hrear){
        int wcnt=wrear-wfront;
        for(int k=0;k<wcnt;k++){
            int y=wy[wfront][0], x=wy[wfront][1]; wfront++;
            for(int d=0;d<4;d++){
                int ny=y+dy[d], nx=x+dx[d];
                if(ny<0||ny>=R||nx<0||nx>=C) continue;
                if(map_[ny][nx]=='.'){
                    map_[ny][nx]='*';
                    wy[wrear][0]=ny; wy[wrear][1]=nx; wrear++;
                }
            }
        }

        int hcnt=hrear-hfront;
        for(int k=0;k<hcnt;k++){
            int y=hy[hfront][0], x=hy[hfront][1]; hfront++;
            for(int d=0;d<4;d++){
                int ny=y+dy[d], nx=x+dx[d];
                if(ny<0||ny>=R||nx<0||nx>=C) continue;
                if(map_[ny][nx]=='D') return dist[y][x]+1;
                if(map_[ny][nx]=='.' && dist[ny][nx]==-1){
                    dist[ny][nx]=dist[y][x]+1;
                    hy[hrear][0]=ny; hy[hrear][1]=nx; hrear++;
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d",&R,&C);
    char line[MAX+1];
    for(int i=0;i<R;i++){
        scanf("%s",line);
        for(int j=0;j<C;j++){
            map_[i][j]=line[j];
            if(line[j]=='S'){ sy=i; sx=j; }
            else if(line[j]=='*'){ wy[wrear][0]=i; wy[wrear][1]=j; wrear++; }
        }
    }
    hy[hrear][0]=sy; hy[hrear][1]=sx; hrear++;

    int ans=bfs();
    if(ans!=-1) printf("%d\n",ans);
    else printf("KAKTUS\n");
    return 0;
}
