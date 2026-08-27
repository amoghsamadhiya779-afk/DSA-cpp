#include<vector>
#include<iostream>
using namespace std;

/*
 LEETCODE#229 :Majority Element 2\

*/

vector<int> MajorityElement(vector<int>&nums){
    int n= nums.size();

    int cnt1=0;
    int cnt2=0;
    int ele1=INT_MIN;
    int ele2=INT_MIN;

for(int i=0;i<n;i++){
    if ( cnt1 == 0  && ele2 != nums[i]){
        cnt1=1;
        ele1=nums[i];
    }

    else if (cnt2 ==0 && ele1 !=nums[i])
      {
        cnt2=1;
        ele2= nums[i];

      }
    else if (nums[i]==ele1) cnt1++;
    else if (nums[i]==ele2) cnt2++; 
    else {
        cnt1 --;
        cnt2 --;
    } 

}

vector <int> ls;
 cnt1 =0;
 cnt2=0;

 for (int i=0;i<n;i++){

 
    if( ele1==nums[i]) cnt1++;
    if (ele2==nums[i]) cnt2++;

 }
 int min =(int) (n/3) +1{
    if (cnt1 >= min ) ls.push_back();
    if(cnt2 >=min ) ls.push_back();
    sort(ls.begin() ,ls.end())
    return  ls;

 }
};