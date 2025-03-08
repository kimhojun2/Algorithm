#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    size_t firstNonZero = n_str.find_first_not_of('0');
    
    if (firstNonZero == string::npos) {
        return "0";
    }

    return n_str.substr(firstNonZero);
}