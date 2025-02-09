#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        if(count(result.begin(),result.end(),nums[i])==0){
            answer++;
            result.push_back(nums[i]);
            if(answer>=nums.size()/2){
                break;
            }
        }
    }
    return answer;
}