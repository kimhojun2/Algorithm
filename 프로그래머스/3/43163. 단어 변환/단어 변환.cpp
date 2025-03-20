#include <string>
#include <vector>

using namespace std;

bool visited[50];
int answer = 50;

bool check(string A, string B){
    int cnt = 0;
    for(int i=0; i<A.size();i++){
        if(A[i]!=B[i]) cnt++;
        if(cnt>1) return false;
    }
    return true;
}


void dfs(string begin, string target, vector<string>& words, int level){
    if(answer <= level) return;
    if(begin == target){
        answer = min(answer, level);
        return;
    }
    
    for(int i=0;i<words.size();i++){
        if(check(begin, words[i]) && !visited[i]){
            visited[i] = true;
            dfs(words[i],target,words,level+1);
            visited[i] = false;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if(answer==50) answer = 0;
    
    return answer;
}