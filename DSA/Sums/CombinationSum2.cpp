#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void findCombination(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(target==0){
            ans.push_back(ds);
            return;

        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind&&arr[i]==arr[i-1])continue;
            if (arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombination(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();

        }
    }
    public:
     vector<vector<int>> combinationSum2(vector<int>&candidates,int target){
     sort(candidates.begin(),candidates.end());
     vector<vector <int>> ans;
     vector<int>ds;
     findCombination(0,target,candidates,ans,ds);
     return ans;
    }
};
int main() {
    Solution sol;

    // Test Case 1: Standard case with duplicates
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    vector<vector<int>> result1 = sol.combinationSum2(candidates1, target1);
    
    cout << "Test Case 1 (Target 8): ";
    for (const auto& combo : result1) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) cout << combo[i] << (i < combo.size() - 1 ? "," : "");
        cout << "] ";
    }
    cout << endl;

    // Test Case 2: Small set
    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    vector<vector<int>> result2 = sol.combinationSum2(candidates2, target2);

    cout << "Test Case 2 (Target 5): ";
    for (const auto& combo : result2) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) cout << combo[i] << (i < combo.size() - 1 ? "," : "");
        cout << "] ";
    }
    cout << endl;

    return 0;
}

