#include <iostream>
#include <vector>
using namespace std;

void generateSubsequences(string &s, int index, string current, vector<string> &result) {
    if (index == s.size()) {
        result.push_back(current);
        return;
    }
    // Exclude the current character
    generateSubsequences(s, index + 1, current, result);
    // Include the current character
    generateSubsequences(s, index + 1, current + s[index], result);
}

int main() {
    string s = "abc";
    vector<string> subsequences;
    generateSubsequences(s, 0, "", subsequences);

    // Print all subsequences
    for (const string &subseq : subsequences) {
        cout << "\"" << subseq << "\" ";
    }
    return 0;
}
