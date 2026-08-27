// Heros vs Villans 

//Greedy alone gives a wrong answer here . // This is binary search on answers +siimulation 

// Problem . M heros , each with health H . N villains , villan i has health v[i] . 

/*
Problem. M heroes, each with health H. N villains, villain i has health V[i]. Heroes fight villains in order
.Hero health h vs villain V: if h > V the villain dies and h -= V; if h < V the hero is out and the villain survives; 
if h == V both are out. Find the minimum number of villains to remove from the front so all remaining villains are defeated.
*/

/*
Why greedy fails . The tempting shortcut is "remove villains utill the
remaining sum is  <= M *H ."That's Wrong " . Take M=2, H=5, V=[6].

Sum is 6 , capacity is 10 - but each hero individually has only 5 health and loses to a 6-health 
vilian without damaging it .


Correnct measure : 
Monotonicity if removing k villains wins , removing k+1 also wins -- hero face a strict subset with same starting health , Monotone predicate -->Binary search on the answers
Feasibility check :simulate . O(N), PER CHECK , O (N log N )total.

*/

#include <bits/stdc++.h>
using namespace std;
int n ;
long long M,H;

vector<long long > v;

bool canWin(int start){
    long long heroesLeft =M , cur=H;
    int i = start;
    while(i<n){
        if (cur >v[i]){
            cur -= v[i];
            i++;

        }else if (cur == v[i]){
            i++;
            heroesLeft--;
            cur =H;

        }
        if(heroesLeft ==0 && i<n) return false;

    }
    return true;

}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n >>M>> H;
    v.resize(n);
    for (int i=0; i<n; i++)
    cin>> v[i];

    int lo =0 , hi =n,ans =n;
    while (lo <= hi){
        int mid = lo +(hi-lo)/2;
        if (canWin(mid)) {
            ans=mid; hi = mid -1;
        }
        else lo = mid +1;

     }
     cout<<ans <<"\n";
     return 0;

}