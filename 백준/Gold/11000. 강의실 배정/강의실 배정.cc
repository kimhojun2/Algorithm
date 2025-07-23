#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<vector<int>> arr;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        arr.push_back({ end, start });
    }

    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; 
        });

    priority_queue<int, vector<int>, greater<int>> classroom;
    classroom.push(arr[0][0]);

    for (int i = 1; i < N; i++) {
        if (classroom.top() <= arr[i][1]) {
            classroom.pop(); 
        }
        classroom.push(arr[i][0]);
    }

    cout << classroom.size();
    return 0;
}
