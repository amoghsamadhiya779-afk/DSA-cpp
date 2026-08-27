/*W2 — Gym Energy (Official Q12)

Same shape as W1, but sorted the other way. Understanding why is the point.

Problem. Energy E. N exercises, exercise i drains A[i]. Each exercise may be performed at most twice. Find the minimum number of exercises to drain your energy to 0 or below. Return -1 if impossible.

Derive.

Minimising a count to reach a threshold → take the largest contributions first. Opposite of W1, because the objective flipped from "how many can I do" to "how few do I need."
Each at most twice → treat it as 2N available items, or just take each sorted element twice in sequence.
Impossible check: if 2 × sum(A) < E, no arrangement works → -1. Do this first.*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    long long E;
    int n ; 
    cin>>E>>n;

    vector<long long >a(n);
    for(int i=0 ;i<n;i++)
    cin>>a[i];

    long long total =0;
    for(long long v:a) total +=v;
    if(2*total <E){
        cout<<-1<<"\n";
        return 0;

    }
    sort (a.rbegin(),a.rend());  //descending

    long long drained =0;
    int count =0;
    for(int i=0; i<n && drained <E ;i++){
        for (int rep=0; rep<2 && drained <E;rep++){
            drained +=a[i];
            count ++;

        }
    }
    cout<<count<<"\n";
    return 0;
    
};