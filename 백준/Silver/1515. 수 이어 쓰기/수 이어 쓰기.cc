#include <iostream>
#include <string>
using namespace std;

int main() {
    string nums;
    cin >> nums;
    int idx = 0;
    int n = 0; 

    while (true) {
        n++;
        string n_str = to_string(n);

        for (char s : n_str) {
            if (nums[idx] == s) { 
                idx++;
                if (idx >= nums.length()) {
                    cout << n << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
