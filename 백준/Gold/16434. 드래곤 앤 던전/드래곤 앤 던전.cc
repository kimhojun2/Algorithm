#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N;
long long hero_atk;

struct Room {
	int t, a, h;
};

Room arr[123456];


bool check(long long max_hp, long long hero_atk) {
	long long curr_hp = max_hp;
	long long curr_atk = hero_atk;

	for (int i = 0; i < N; i++) {
		Room now = arr[i];

		if (now.t == 1) { // 몬스터 방
			long long cnt = (now.h + curr_atk - 1) / curr_atk;
			long long damage = (cnt - 1) * (long long)now.a;

			curr_hp -= damage; // 대미지 차감
			if (curr_hp <= 0) return false; // 사망 판정
		}
		else { // 포션 방
			curr_atk += now.a;
			curr_hp += now.h;
			if (curr_hp > max_hp) curr_hp = max_hp; // 최대 체력 초과 방지
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> hero_atk;

	for (int i = 0;i < N;i++) {
		cin >> arr[i].t >> arr[i].a >> arr[i].h;
	}

	long long low = 1;
	long long high = 1e18;
	long long ans = 1e18;

	while (low <= high) {
		long long mid = low + (high - low) / 2;

		if (check(mid, hero_atk)) {
			high = mid - 1;
			ans = min(ans, mid);
		}
		else {
			low = mid + 1;
		}

	}

	cout << ans;

	return 0;
}