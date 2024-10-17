#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& parcels, int n, long long extra_parcels, long long target) {
    long long needed = 0;
    for (int i = 0; i < n; i++) {
        if (parcels[i] < target) {
            needed += target - parcels[i];
        }
    }
    return needed <= extra_parcels;
}

int main() {
    int n = 5;
    long long extra_parcels = 25;
    vector<int> parcels = {7, 5, 1, 9, 1};
    
    long long s = *max_element(parcels.begin(), parcels.end());
    long long end = s + extra_parcels;
    long long ans = -1;
    
    while (s <= end) {
        long long mid = s + (end - s) / 2;
        if (isPossible(parcels, n, extra_parcels, mid)) {
            ans = mid;
            // If solution is possible at mid, try to minimize further
            end = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}