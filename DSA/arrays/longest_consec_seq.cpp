#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM: Longest Consecutive Sequence (LeetCode 128)
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example: [100, 4, 200, 1, 3, 2]
Output: 4 (The sequence is [1, 2, 3, 4])

Constraint: Must run in O(N) time!
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int longest = 1;
        
        // 1. Put everything into an unordered_set to achieve O(1) lookups
        unordered_set<int> st(nums.begin(), nums.end());
        
        // 2. Iterate through the set
        for (auto it : st) {
            
            // 3. OPTIMAL TRICK: Only start counting if it is the FIRST number of a sequence.
            // How do we know it's the first? If (it - 1) is NOT in the set!
            if (st.find(it - 1) == st.end()) {
                
                int current_num = it;
                int current_count = 1;
                
                // Keep checking for the next consecutive number in O(1) time
                while (st.find(current_num + 1) != st.end()) {
                    current_num += 1;
                    current_count += 1;
                }
                
                // Update the maximum length found so far
                longest = max(longest, current_count);
            }
        }
        
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: " << sol.longestConsecutive(nums) << endl; 
    // Should output: 4
    return 0;
}