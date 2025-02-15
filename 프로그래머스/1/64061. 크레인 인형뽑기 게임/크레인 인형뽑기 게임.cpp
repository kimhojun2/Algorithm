#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    for(auto x : moves){
        for(int y=0;y<board.size();y++){
            if(board[y][x-1] != 0){
                if(!basket.empty() && basket.top()==board[y][x-1]){
                    basket.pop();
                    answer +=2;
                }
                else{
                    basket.push(board[y][x-1]);
                }
                board[y][x-1] = 0;
                break;
            }
        }
    }
    return answer;
}