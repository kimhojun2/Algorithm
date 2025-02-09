#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0;i<photo.size();i++){
        int sum = 0;
        for(int j=0;j<photo[i].size();j++){
            auto it = find(name.begin(),name.end(),photo[i][j]);
            if(it != name.end()){
                sum += yearning[distance(name.begin(), it)];    
            }
            
        }
        answer.push_back(sum);
    }
    
    return answer;
}