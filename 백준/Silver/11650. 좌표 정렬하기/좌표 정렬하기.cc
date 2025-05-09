#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {	// x가 같은 경우에만, 
		return a.second < b.second;	// y를 기준으로 오름차순
	}
	else {
		return a.first < b.first;	// x를 기준으로 오름차순
	}
}

int main(){
	int n, x, y;
    	vector<pair<int, int>> v; // 이차원 벡터 선언
	cin >> n;

	for (int i = 0; i < n; i++){
    	cin >> x >> y;
    	// 첫 번째 - 이차원 벡터 입력 방법
    	v.push_back({x, y});
        // 두 번째 - 이차원 벡터 입력 방법
        // v.push_back(make_pair(x, y));
    }
    
	sort(v.begin(), v.end(), compare); // 오름차순
    
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " "<< v[i].second << "\n";
	}
    
    return 0;
}