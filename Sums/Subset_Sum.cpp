#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void SubsetSum(int ind,int sum,vector<int>&arr,int N,vector<int>&sumSubset){
        if (ind==1){
            sumSubset.push_back(sum);
            return;

        }
        //pick an element
        SubsetSum(ind+1,sum+arr[ind],arr,N,sumSubset);

        //Do not pick conditon
        SubsetSum(ind+1,sum,arr,N,sumSubset);

    }
public:
vector<int>subsetSums(vector<int>arr,int N){
    vector<int>sumSubset;
    SubsetSum(0,0,arr,N,sumSubset);
    sort(sumSubset.begin(),sumSubset.end());
    return sumSubset;}
int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {2, 3};
    int N1 = 2;
    vector<int> result1 = sol.subsetSums(arr1, N1);
    cout << "Test Case 1: ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {5, 2, 1};
    int N2 = 3;
    vector<int> result2 = sol.subsetSums(arr2, N2);
    cout << "Test Case 2: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;

}    
};