#include <bits/stdc++.h>
using namespace std;
int MaxLen(int A[],int n){
    unordered_map <int,int> mpp;
    int max=0;
    int sum =0;
    for (int i=0;i<n;i++){
        sum+=A[i];
       if(sum==0){
        max=i+1;
       } 
       else{
         if (mpp.find(sum)!=mpp.end()){
            max = std::max(max,i-mpp[sum]);
         }
         else{
            mpp[sum]=i;

         }
       }
    }
    return max;
}; 