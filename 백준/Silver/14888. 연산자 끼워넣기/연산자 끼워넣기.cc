#include <iostream>

#define MIN -1000000001
#define MAX 1000000001
using namespace std;

int arr[11] = { 0, };
int sign[4] = { 0, };
int N;
int Max_ans = MIN;
int Min_ans = MAX;
void calc(int arr_idx, int sum) {
	if (arr_idx == N) {
		if (sum < Min_ans) {
			Min_ans = sum;
		}
		if (sum > Max_ans) {
			Max_ans = sum;
		}
	}
	for (int idx = 0;idx < 4;idx++) {
		if (sign[idx] !=0) {
			sign[idx]--;
			switch (idx) {
			case 0: calc(arr_idx+1, sum + arr[arr_idx]);break;
			case 1:calc(arr_idx+1, sum - arr[arr_idx]);break;
			case 2:calc(arr_idx+1, sum * arr[arr_idx]);break;
			case 3:calc(arr_idx + 1, sum / arr[arr_idx]);break;
			}
			sign[idx]++;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	for (int i = 0;i < 4;i++) {
		cin >> sign[i];
	}
	calc(1, arr[0]);
	cout << Max_ans << '\n' << Min_ans;
	

	return 0;
}