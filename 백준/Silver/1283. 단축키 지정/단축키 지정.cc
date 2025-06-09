#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
bool alpha[26] = { false, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin.ignore();

    vector<string> result;

    for (int i = 0; i < N; i++) {
        string S;
        getline(cin, S);

        bool assigned = false;
        string modified = "";
        vector<string> words;
        string temp = "";

        for (char ch : S) {
            if (ch == ' ') {
                words.push_back(temp);
                temp = "";
            }
            else {
                temp += ch;
            }
        }
        if (!temp.empty()) words.push_back(temp);

        for (int w = 0; w < words.size(); w++) {
            char c = words[w][0];
            char upper = toupper(c);
            if (!alpha[upper - 'A']) {
                alpha[upper - 'A'] = true;
                words[w].insert(0, "[");
                words[w].insert(2, "]");
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            for (int w = 0; w < words.size(); w++) {
                for (int k = 0; k < words[w].size(); k++) {
                    char c = words[w][k];
                    char upper = toupper(c);
                    if (!alpha[upper - 'A']) {
                        alpha[upper - 'A'] = true;
                        words[w].insert(k, "[");
                        words[w].insert(k + 2, "]");
                        assigned = true;
                        break;
                    }
                }
                if (assigned) break;
            }
        }

        for (int w = 0; w < words.size(); w++) {
            modified += words[w];
            if (w != words.size() - 1) modified += " ";
        }

        result.push_back(modified);
    }

    for (auto& line : result) {
        cout << line << '\n';
    }

    return 0;
}
