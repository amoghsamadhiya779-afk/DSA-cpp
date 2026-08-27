//  SORT COLORS (DUTCH NATIONAL FLAG)

// THREE pointers . Named explicitlt in your Tier -1 List.

// Problem  Arrays : - Array of only 0s, 1s , 2s.


// Sort in place in a single pass, O(1) space.

/// Primarily 3 regions 

// [0,low-1] --> all 0s
// [low, mid-1] --> all 1s
// [high+1,n-1] --> all 2s
// [mid,high]  --> unexamined

/*
At a[mid]: If 0, swap into the 0- region and advance both low and mid . If 1 is already in place -- just mid++. 

If 2 , swap to the 2- region and high-- without advancing mid , because the value swapped in from high has not been examined yet.



*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>> n;

    vector<int> a(n);
    for(int i =0; i<n; i++)
    cin>>a[i];


    int low =0, mid , high  =n-1;
    while(mid<=high)
   {
    if (a[mid]==0){
        swap (a[low],a[mid]);
        low ++; mid++;

    }
    else if (a[mid]==1){
        mid++;
    }
    else {
        swap(a[mid], a[high];
        high--;)
    }
   }
   for (int i=0; i<n; i++)
   cout<<a[i]<<(i+1<n ? ' ' :'\n');
   return 0;
   
}