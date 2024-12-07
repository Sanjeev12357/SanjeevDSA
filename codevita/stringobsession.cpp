#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int solve(string cur, const vector<string>& substrings, unordered_map<string, int>& mp) {
    if (mp.find(cur) != mp.end()) return mp[cur];

    mp[cur] = 0;

    for (const string& sub : substrings) {
        size_t idx = cur.find(sub);

        while (idx != string::npos) {
            string updated = cur.substr(0, idx) + cur.substr(idx + sub.size());

            mp[cur] = max(mp[cur], 1 + solve(updated, substrings, mp));

            idx = cur.find(sub, idx + 1);
        }
    }

    return mp[cur];
}

int main() {
    int totalSubstr;
    cin >> totalSubstr;

    vector<string> arr(totalSubstr);
    for (auto& cur : arr) cin >> cur;

    string s;
    cin >> s;

    unordered_map<string, int> mp;
    cout << solve(s, arr, mp) << endl;

    return 0;
}