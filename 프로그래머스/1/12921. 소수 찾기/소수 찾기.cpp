#include <vector>

using namespace std;

int solution(int n) {
    vector<bool> is_prime(n + 1, true);
    int answer = 0;
    
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님

    for (int i = 2; i * i <= n; i++) { // i가 n의 제곱근까지
        if (is_prime[i]) { // i가 소수이면
            for (int j = i * i; j <= n; j += i) { // i의 배수들을 모두 제거
                is_prime[j] = false;
            }
        }
    }

    // 소수 개수 세기
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) answer++;
    }

    return answer;
}