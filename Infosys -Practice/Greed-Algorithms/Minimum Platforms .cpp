#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin>>n;
    vector<long long > arr(n), dep(n);
    for(int i=0; i<n; i++)
    cin>>arr[i];
    for (int i=0 ;i<n;i++)
    cin>>dep[i];

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i=0, j=0 , cur =0, best =0;
    while (i<n){
        if (arr[i] <=dep[j]){
            cur++; i++;
            best = max(best,cur);
        }
        else {
            cur--; 
            j++;

        }
    }
    cout<<best << "\n";
    return 0;
    


};