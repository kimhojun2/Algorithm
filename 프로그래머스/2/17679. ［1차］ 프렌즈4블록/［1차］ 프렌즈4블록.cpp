#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> new_arr;
int answer = 0;
bool tf = true;

int check(int m, int n, vector<string> &arr){
    new_arr = arr;
    for(int i=0;i<m-1;i++){
        char now;
        for(int j=0;j<n-1;j++){
            now = arr[i][j];
            if(arr[i+1][j] == now && arr[i+1][j+1] == now && arr[i][j+1] == now && now !='*'){
                tf = true;
                new_arr[i][j] = new_arr[i+1][j] = new_arr[i][j+1] = new_arr[i+1][j+1] = '*';
            }
        }
    }
    
    if(!tf) return 0;
    
    arr = new_arr;
    int new_answer = 0;
    for(int j = 0; j < n; j++) {
        string temp = "";
        for(int i = 0; i < m; i++) {
            if(arr[i][j] != '*') temp += arr[i][j];
            else new_answer++;
        }
        while(temp.size() < m) temp = '*' + temp; 
        for(int i = 0; i < m; i++) {
            arr[i][j] = temp[i];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        }
    }
    answer = new_answer;
    return 0;
}

int solution(int m, int n, vector<string> arr) {
    while(tf){
        tf = false;
        check(m,n,arr);    
    }
    return answer;
}