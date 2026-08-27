
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;

    vector<long long > h(n);
    for(int i=0; i<n; i++) cin>> h[i];

    int l=0, r=n-1;
    long long best =0;
    while(l<n){
        long long area = (long long )(r-1) * min (h[l],h[r]);
        best = max (best, area);

        if (h[l]<h[r]) l++:

        else r--;

    }
    cout<<best<<"\n";

    return 0;
    
}