#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int>idx;
    map<int,string>rank;
    for(int i=0;i<players.size();i++){
        idx[players[i]] = i;
        rank[i] = players[i];
    }
    for(int i=0;i<callings.size();i++){
        // 지금 호명한 선수 이름
        string now_name = callings[i];
        // 지금 호명한 선수의 지금 등수
        int now_rank = idx[now_name];
        // 추월 당한 선수의 지금 등수
        int overtaken_rank = now_rank-1;
        // 추월 당한 선수 이름
        string overtaken_name = rank[overtaken_rank];
        //이름교체
        rank[now_rank] = overtaken_name;
        rank[now_rank-1] = now_name;
        //등수교체
        idx[now_name] = overtaken_rank;
        idx[overtaken_name] = now_rank;
        
    }
    for(auto ranking: rank){
        answer.push_back(ranking.second);
    }
    return answer;
}