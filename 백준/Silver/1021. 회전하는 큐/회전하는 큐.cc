#include <iostream>
#include <deque>
using namespace std;

deque <int> dq;
int main() {
    int n, m, r, l, i, cnt = 0, tmp;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        dq.push_back(i);
    } // 숫자 넣기
    while(m--){
        cin >> tmp;
        for(i=0; i< dq.size(); i++){
            if(dq[i] == tmp){
                r = i;
                l = dq.size() - r;
                break;
            }
        } // tmp의 위치 찾고, 왼쪽과 오른쪽의 길이 구하기
        if(r <= l){
            while(1){
                if(dq.front() == tmp){
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        } // 오른쪽이 왼쪽보다 작다면 오른쪽으로 회전
        else if(r > l){
            while(1){
                if(dq.front() == tmp){
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            } // 왼쪽이 오른쪽보다 작다면 왼쪽으로 회전
        }
    }
    cout << cnt;
    return 0;
}