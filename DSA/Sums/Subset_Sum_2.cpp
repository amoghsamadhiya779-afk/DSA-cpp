#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void find_Subsets(int ind,vector<int>&nums ,vector<int>&ds,vector<vector<int>>&ans){
      ans.push_back(ds);
      for(int i = ind ;i < nums.size(); i++){
        if (i > ind && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        find_Subsets (i+1,nums,ds,ans);
        ds.pop_back();

    }
    

}
public:
vector<vector<int>> subsetsWithDup(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int>ds;
    sort (nums.begin(),nums.end());
    find_Subsets(0,nums,ds,ans);
    return ans;
}
};
int main() {
    Solution sol;
    // Test Case 1
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> result1 = sol.subsetsWithDup(nums1);
    cout << "Test Case 1: ";
    for (const auto& subset : result1) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) cout << subset[i] << (i < subset.size() - 1 ? "," : "");
        cout << "] ";
    }
    cout << endl;
    // Test Case 2
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = sol.subsetsWithDup(nums2);
    cout << "Test Case 2: ";
    for (const auto& subset : result2) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) cout << subset[i] << (i < subset.size() - 1 ? "," : "");
        cout << "] ";
    }
    cout << endl;
    return 0;
}