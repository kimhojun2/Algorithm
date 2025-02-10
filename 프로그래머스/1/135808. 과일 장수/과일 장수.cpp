#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    priority_queue<int> pq(score.begin(), score.end()); 

    while (pq.size() >= m) { 
        vector<int> box;     
        
        for (int i = 0; i < m; i++) { 
            box.push_back(pq.top());
            pq.pop();
        }

        int min_score = box.back();
        answer += min_score * m;     
    }

    return answer;
}
