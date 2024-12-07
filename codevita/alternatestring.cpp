#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define vi vector<int>


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;   cin >> s;

    int n = s.size();

    vi arr(n);

    int res = 0;

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        res += arr[i];
    }

    int cur = arr[0];

    for(int i=1; i<n; i++)
    {
        if(s[i] == s[i-1])
        {
            cur = max(cur, arr[i]);
        }
        else
        {
            res -= cur;
            cur = arr[i];
        }
    }

    res -= cur;

    cout << res;
    
}