#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// Returns LCM of array elements
int findlcm(vector< int>arr, int n)
{
    // Initialize result
    int ans = arr[0];
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector< int>v;
    for(int i=0;i< n;i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    int a = *min_element(v.begin(), v.end());
   auto it = find(v.begin(), v.end(), a);
    if (it != v.end())
        v.erase(it);
    int res;
    res = findlcm(v, n-1);
    cout<< res+a;
}