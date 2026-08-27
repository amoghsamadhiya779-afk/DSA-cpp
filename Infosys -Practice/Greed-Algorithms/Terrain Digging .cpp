// Greedy sweep + maths step .

/*
Sea levels L[1...N] . Make the terrain strictly decreasing (L[i-1]>L[i])
every i>= 2 )   On day D the team reduces each schedule segment by 2^(D-1).You may schedue any segments on any days . Minimum days 

Dervive 
 : Greedy sweep : Go left to right . If L[i] >= L[i-1],segment i must come down to at most
 L[i-1]-1 . The reduction is needed is L

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n ; 
    cin>> n;

    vector<long long > L(n);
    for(int i=0; i<n; i++)cin>>L[i];

    long long maxDig =0;
    for (int i=0 ; i+1<n; i++){

        if (L[i+1]>=L[i]){
            maxDig=max(maxDig, L[i+1]-L[i]+1);
            L[i+1] = L[i]-1;

        }
    }

    int days =0;
    long long capacity =0;
    while (capacity <maxDig){
        capacity += (1LL<days);
        days;
    }
    cout<<days << "\n";
    return 0;
};
    