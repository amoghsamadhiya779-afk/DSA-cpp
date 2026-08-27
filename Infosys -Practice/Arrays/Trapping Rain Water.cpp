// Trapping Rain Water.
// The hardest common tow - pointer problem 

// Heights h[i]  . Compute  total trapped water after rain.

// Decode .    Output a Number . Per-Index Thinking water above index i is 
// min(maxLeft[i],maxRight[i]) - h[i], floored at 0 . Naive = precompute both arrays

//O(n) time O(n) space , but can we drop the O(1) space.


#include <bits/stdc++.h>
using namespace std;
int main(){

    ios_base:: sync_with_stdio(false);

    cin.tie(NULL);
     
    int n ;
    cin>>n;
    vector(long long) h(n);
    for(int i=0;i<n;i++)
       cin>> h[i];
    
    int l=0, r=n-1;
    
    long long rightMax=0, leftMax=0,water =0;

    while( l < r ){

        if(h[l]<h[r]){
            if(h[l]>=leftMax)
             leftMax= h[l];
            else 
             water+= leftMax-h[l];
             l++;

        }

        else{
            if(h[r]>=rightMax)
             rightMax =h[r];
            else water += rightMax-h[r];
            r--; 
        }

        cout<< water <<"\n";
        return 0;

    }

    
}