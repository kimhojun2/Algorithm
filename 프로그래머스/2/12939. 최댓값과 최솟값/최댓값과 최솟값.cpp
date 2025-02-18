#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream iss(s);
    string word;
    vector<int>arr;
    while (iss >> word) {
        cout << word;
        arr.push_back(stoi(word));
    }
    sort(arr.begin(),arr.end());
    answer = to_string(arr[0]) + " " + to_string(arr[arr.size()-1]);
    
    return answer;
}