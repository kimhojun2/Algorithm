#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int>idx_lst;
    int L = id_list.size();
    vector<int> answer(L,0);
    for(int i=0;i<L;i++){
        idx_lst[id_list[i]] = i;
    }
    vector<vector<int>>check(L,vector<int>(L,0));
    vector<int>total(L,0);
    for(auto names : report){
        istringstream name(names);
        string A,B;
        name >> A >> B;
        int idx_A = idx_lst[A];
        int idx_B = idx_lst[B];
        if(check[idx_A][idx_B]!=0) continue;
        check[idx_A][idx_B] = 1;
        total[idx_B]++;
    }
    for(int i=0;i<total.size();i++){
        if(total[i]>=k){
            for(int y=0;y<L;y++){
                if(check[y][i] == 1){
                    answer[y]++;
                }
            }
        }
    }
    
    
    return answer;
}