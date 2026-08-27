// Question 15 --  GIFT BOXES 

//The problem 

/* N gifts in a row , gift i has type A[i] . Pack them into exact K boxes, 

, where each box is a contiguous subarray of gifts (no gift skipped , no reordereing , no empty box). The value of box is it's 

count of distinct type. Maximise the total across all K boxes
Input 7/2 /1 3 3 1 4 4 4   Output 5

Derive .1. Where do the K-1 cut points go ? Equivalenty : For the J-th box, where does it start and end 
2. State  . To decide box j's boundary i need : how many gifts have been consumed so far, and how 
many boxes I've places so far . That's (i,j) -- position in the array , number of boxes used . 

dp[i][j]  = maximum total value usig the First i gifts , Split into j boxes.




*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k ;
    cin>>n>>k;
    vector<int> a(n+1);

    for(int i=1; i<=n; i++)
    cin>>a[i];


    const long long NEG = LLONG_MIN/2;
    vector<vector<long long >> dp(n+1,vector<long long > (k+1,NEG));
    dp[0][0] = 0;

    for (int j=1; j<=k;j++){
        for(int i=j ; i<= n ; i++)
        {
             unordered_map<int, int> freq;
             int distinct =0;

             // walk the boc [p+1 ...i] backward from 0 , p from i-1 down to j -1
             for (int p=i-1 ; p>=j-1; p--){
                if (dp[p][j-1] <= NEG) continue;
                if(freq[a[p+1]++ ==0]) distinct++;
                dp[i][j]= max(dp[i][j],dp[p][j-1] +distinct);

             }

        }



}

cout<<dp[n][k]<<"\n";
return 0;
};