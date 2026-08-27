//Maximum Subbarray / Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<long long> a(n);
    for(auto &x : a) cin>>x;
    long long best=a[0], curr=a[0];

    for(int i=1;i<n;i++){
        curr=max (a[i] ,curr+a[i]);
        best =max(best,curr);

    }

    cout<<best<<"\n";

    return 0;


}

int main (){
    int n;
    cin>>n;
    vector<long long>a(n);
    for (auto &x:a) cin>>x;
    long long best = a[0],curra[0];


    for (int i=1;i<n;i++){
        curr=max(a[i],curr+a[i]);
        best = max (best,curr);

    }

    cout<<best<<"\n";
    return 0;
    
}