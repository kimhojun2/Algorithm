#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> order = {1, 2, 3, 1};

    for (int i = 0; i < ingredient.size(); i++) {
        if (i >= 3 &&
            ingredient[i-3] == 1 &&
            ingredient[i-2] == 2 &&
            ingredient[i-1] == 3 &&
            ingredient[i]   == 1) {
            answer++;
            ingredient.erase(ingredient.begin() + i - 3, ingredient.begin() + i + 1);
            i -= 4;
        }
    }

    return answer;
}
