#include <string>
#include <vector>
#include <iostream>
using namespace std;

pair<int,int> count_num(vector<string>& board){
    int y = 0;
    int x = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='O') y++;
            else if(board[i][j]=='X') x++;
        }
    }
    return {y,x};
}




int win(vector<string>& board){
    bool o_win = false;
    bool x_win = false;
    
    //  row
    for(int i=0; i<3; i++){
        if(board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == 'O') o_win = true;
            else if(board[i][0] == 'X') x_win = true;
        }
    }

    // col
    for(int j=0; j<3; j++){
        if(board[0][j] != '.' && board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            if(board[0][j] == 'O') o_win = true;
            else if(board[0][j] == 'X') x_win = true;
        }
    }
    
    //  diagonal
    if(board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == 'O') o_win = true;
        else if(board[0][0] == 'X') x_win = true;
    }
    if(board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == 'O') o_win = true;
        else if(board[0][2] == 'X') x_win = true;
    }

    if(o_win && x_win) return 3;
    if(o_win) return 1;
    if(x_win) return 2;
    return 0;
}

int solution(vector<string> board) {
    pair<int,int> p = count_num(board);
    int cnt_O = p.first;
    int cnt_X = p.second;

    // O와 X의 수 차이가 잘못된 경우
    if(cnt_X > cnt_O || cnt_O > cnt_X + 1) return 0;

    int n = win(board);

    // O와 X가 동시에 이김 -> 잘못된 게임 상태
    if(n == 3) return 0;

    // O가 이겼는데 O가 X보다 1개 더 많지 않으면 잘못된 상태
    if(n == 1 && cnt_O != cnt_X + 1) return 0;

    // X가 이겼는데 O와 X 수가 같지 않으면 잘못된 상태
    if(n == 2 && cnt_O != cnt_X) return 0;

    return 1;
}

