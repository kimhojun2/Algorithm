#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int rotate(int y1, int x1, int y2, int x2, vector<vector<int>>& matrix){
    int N = y2; int M = x2;
    int y = --y1; int x = --x1;
    int before = matrix[y][x];
    int min = before;
    
    for(int d=0;d<4;d++){
        int k = 1;
        while(1){
            int ny = y + dy[d] * k;
            int nx = x + dx[d] * k;
            if(ny < y1 || nx < x1 || ny >= N || nx >= M){
                y = ny - dy[d];
                x = nx - dx[d];
                break;
            }
            int temp = matrix[ny][nx];
            if(min > temp) min = temp;
            matrix[ny][nx] = before;
            before = temp;
            k++;
        }
    }
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    for(int i = 1; i <= rows * columns; i++){
        matrix[(i - 1) / columns][(i - 1) % columns] = i;
    }

    for(int i = 0; i < queries.size(); i++){
        vector<int> now = queries[i];
        int num = rotate(now[0], now[1], now[2], now[3], matrix);
        answer.push_back(num);
    }

    return answer;
}
