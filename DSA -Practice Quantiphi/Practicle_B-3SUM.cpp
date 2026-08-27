//3 sum  

//  end goal to Get the triplets sorted in a lexicographical order


/*
Algorithm

1. Sort the Array
2. For i from 0 to n-3:
If i>0 and a[i]==a[i-1], skip 
target = -a[i], l=i+1, r=n-1
while (l<r): sum = a[l]+a[r]
sum <Target --> l++
sum>Target --->r--
sum==Target ---> record (a[i],a[l], a[r]);

then advance l past duplicates and retreats r past duplicates.
then l++, r--
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
   ios_base :: sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin>> n ;

   vector<long long> a(n);
   for (int i=0;i<n;i++) cin>> a[i];

   vector<array<long long,3>> resuult;
   for (int i=0;i<n-2;i++){
    if(i>0   &&  a[i] ==a[i-1]) continue;
    long long target =-a[i];
    int l=i+1 ,int r=n-1;

    while(l<r){
        long long sum = a[l]+a[r];

        if(sum<target){
            l++;

        }
        else if(sum>target){
            r--;

        }
        else {
            result .push_back({a[i],a[l,a[r]]});

            long long lv =a[l], rv = a[r];
            while (l<r && a[l] ==lv)  l++;
            while (r<l **&& a[r]==rv) r--;

        }
    }

   }
   cout<<result.size()<<"\n";
   for(auto &t :result){
    cout<<t[0]<<" " <<t[1]<<" "<<t[2]<<"\n";

   }

   return 0;
   

 

}