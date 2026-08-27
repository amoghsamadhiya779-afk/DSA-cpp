#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void findCombination(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(ind==arr.size())
        { if(target==0){
            ans.push_back(ds);
        }
        return;

        }
        //pick up the element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();

        }
        //not pick up the element
        findCombination(ind+1,target,arr,ans,ds);

    }
    public:
    vector<vector<int>> combinationSum(vector<int>&candidates,int target){
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
};


int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = sol.combinationSum(candidates1, target1);
    
    cout << "Test Case 1 (Target 7): ";
    for (const auto& combo : result1) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) cout << combo[i] << (i < combo.size() - 1 ? "," : "");
        cout << "] ";
    }
    cout << endl;

    // Test Case 2: Multiple combinations
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> result2 = sol.combinationSum(candidates2, target2);

    cout << "Test Case 2 (Target 8): ";
    for (const auto& combo : result2) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) cout << combo[i] << (i < combo.size() - 1 ? "," : "");
        cout << "] ";
    }
    cout << endl;

    return 0;
};