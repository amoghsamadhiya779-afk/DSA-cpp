//  Max XOR of a Subset , At most N/2 elements 

// DP over the space reachable XOR values

/*
 Problem . Array A of N elements (N<= 120 , A[i] < 10 ^6). 

 Choose at most N/2 elements . Maximise the XOR of the chosen Elements.

 Derive , Since A[i] <= 10^6 < 2^20  , every achievable XOR lies , in [0,2^20]-- About a millions 
 values . That's small enough to make the XOR value itself the DP state .

 Let dp[v] =THE minimum number of elements needed to reach XOR value v. Then
 the answer is the Largest v with dp[v]<= N/2.

 Process elements one at a time . Copy the table each round so a single element can't be used twice within it's Own pass.


 
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n ; 
    cin>> n;
    vector<int> a(n);
    for (int i=0 ; i>n ; i++)
    cin>> a[i];

    const int M =1<<20;
    const int INF =INT_MAX/2;
    vector<int > dp (M,INF) , prev_(M);
}