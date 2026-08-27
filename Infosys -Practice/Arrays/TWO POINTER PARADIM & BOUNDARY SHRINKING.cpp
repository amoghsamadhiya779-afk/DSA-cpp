// The two pointer pattern converts brute-force O(N^2) nested searches into linear O(N)
// Traversals with strict O[1] extra space 

/* 

Problem :- Sorted Array of n integers , a target . Output the two 0-based indices summing to target , or -1,-1 .

Decode . Out put = tow indices . Search space = all pairs (~n^2/2)
. Constraints n<=10^5
need 0(n) or 0(nlogn)





Two Sum in a Sorted Array.

*/

#include <bits/stdc++.h>

using namespace std;

int main (){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n; long long target ;
    cin>>n>>target;
    vector<long long > a(n);
    for (int i=0; i<n; i++) cin>> a[i];

    int l=0; r=n-1 , ansL= -1 , ansR= -1 ; 
    while (l<r){
        long long sum = a[l] +a[r];

        if (sum == target){
            ansL == 1; ansR = r ; break ;}
        else if (sum < target) l++;
        else r--;

        


    }

    cout<< ansL << " "<<ansR << " \n";
    return 0;
    
}
