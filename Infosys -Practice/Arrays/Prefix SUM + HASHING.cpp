// The Question Framing 
/*
1.Given an unsorted array of integers(which can include negative numbers ) and an Integer K, find the Total number of continuous arrays whose sum equals K.
2. Key Indicators (When ot use this)
:-  Continuous Subarray + Sum + Negative Allowed

:-  "Count the nuber of ways / Find the Longest segment "

Constraints upto N=10^5 then 0(n^2), will give a Time Limit Exceeded (TLE)
WE WILL NEED A O(N) sol.


# 1. Initialise current_sum=0 and count =0;

2. Create an Unordered_map  to track how many times you've seen a specific prefix sum. 
3. The Golden Rule : Initiale map[0]=1. This is because if your current_sum exactly equals K , 
current_sum-K =0, You need that 0 in the map to count the subarray that starts from the Very beginning.

4. Iterate through the array. 

: Add the Current element to current_sum.

: Calculate : required = current_sum -K.

If required is in the map, add it's Frequency to count .

: ADD CURRENT_SUM TO THE MAP .

*/

#include <bits/stdc++.h>
using namespace std; 

int main(){

    //Infosys Wingspan Standard fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long k;
  cin>>n>>k;
  vector<long long > a(n);
  for(inti=0;i<n;i++){
    cin>>a[i];

  }
  unordered_map<long long ,int > prefix_freq;

  prefix_freq[0]=1;
  long long current_sum=0;
  long long count =0;

  for(int i=0;i<n;i++){
    current_sum +=a[i];

    long long required_prefix =current_sum-k;

    if(prefix_freq.count (required_prefix)){
        count += prefix_freq[required_prefix];

    }
    prefix_freq[current_sum]++;

  }
  cout<<count<<"\n";
  return 0;


}