#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets; // Store all subsets
        allSubsets.push_back({}); // Start with the empty subset

        // Outer loop to iterate over each element in nums
        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            int n = allSubsets.size(); // Capture the current number of subsets

            // Inner loop to create new subsets based on the existing ones
            for (int j = 0; j < n; j++) {
                vector<int> newSubset = allSubsets[j]; // Copy each existing subset
                newSubset.push_back(currentNum); // Add the current number to it
                allSubsets.push_back(newSubset); // Add the new subset to the result
            }
        }
        return allSubsets;
    }
};
