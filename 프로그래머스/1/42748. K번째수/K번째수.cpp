#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int idx=0;idx<commands.size();idx++){
        int i,j,k;
        i = commands[idx][0] - 1;
        j = commands[idx][1] - 1;
        k = commands[idx][2] - 1;
        vector<int> arr;
        for(int now=i;now<=j;now++){
            arr.push_back(array[now]);
        }
        sort(arr.begin(),arr.end());
        answer.push_back(arr[k]);
    }
    return answer;
}