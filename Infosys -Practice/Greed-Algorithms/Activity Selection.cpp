#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin>>n;
    vector <pair<long long , long long >> act(n);
    for (int i=0; i<n; i++){
        long long s, e ; 
        cin>> s>> e;


    }
    sort (act.begin(), act.end());
    int count =0;
    long long lastEnd = LLONG_MIN;
    for (auto &p :act){
        if (p.second >= lastEnd){
            count ++; lastEnd = p.first;
        }
        
    }
    cout<< count<<"\n";
    return 0;
};