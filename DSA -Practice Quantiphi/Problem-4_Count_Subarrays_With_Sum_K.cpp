// Given an array of n integer  and an integer K, count the contiguous
//subbarrray whose sum equals K.


// Pattern :- Prefix Sum + Hash Map. 


//Contiguous Subarray + Sum equals to K  

//Optimal Approach 

// Let P[i] be the sum of a[0...i]. A subarray (j+1....i) sums to K 
//when P[i] -P[j]  ,ie P[j]=P[i]-K  , So at each i , count how many earlier prefix sums

/*
 Algorithm 


 1. freq[0] =1, prefix   =0 , count =0.
 2. For each element : prefix +=a[i].

 3. Add freq[prefix-K] to count . 
 4. freq[prefix]++.

 ----------------------------
Dry Run

a=[1,2,3,-1,1] K=3

a[0]=1 prefix =1 (prefix += a[i])  need = prefix-3---> -2 freq[need] =0 , count 0  {0:1,1:1}
a[1]=2 prefix =3 need = 0  ,freq[need]=1, count 1 ----> freq after {0:1,1:1,3:1}
a[2]=3 prefix =6 , need= 3 , freq[need]=1,count 2 ----> {....,6:1}
a[3]=-1 ,prefix =5 need =2    req[need] = 0 , count 2  freq after --->{.....,5:1}
a[4]=1  , prefix =5, need =2 freq[need]=1, count =3 , {.........6:2}
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base ::sync_with_stdio(false);

  cin.tie(NULL);
int n;
long long k;
cin>>n>>k;
vector<long long> a(n);
for(int i=0;i<n;i++) cin>> a[i];
unordered_map<long long, long long > freq;
freq[0]=1;
 long long prefix =0;
 long long  count =0; 
for(int i=0;i<n;i++){
  prefix += a[i];
  auto it =freq.find(prefix-K);
  if(it!=freq.end()) count += it->second;
  freq[prefix]++;
  



}

cout<<count <<"\n";
return 0;


}