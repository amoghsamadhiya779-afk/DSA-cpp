#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void recurPermute(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,int freq[]){
    if (ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            recurPermute(ds,nums,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
    }

    public:
    vector<vector<int>>permute(vector<int>&nums){
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);
    
    cout << "Permutations: " << endl;
    for (const auto& p : result) {
        cout << "[";
        for (size_t i = 0; i < p.size(); ++i) {
            cout << p[i] << (i < p.size() - 1 ? "," : "");
        }
        cout << "] ";
    }
    return 0;
}