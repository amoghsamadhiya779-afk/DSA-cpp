#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long val;
    cin>>n>>val;

    vector<long long > a(n);
    for(int i=0; i<n;i++)
    cin>>a[i];
    int left =0;
    int right =n;
    while (left<right){
        if(a[left] == val){
            a[left]= a[right -1];
            right--;

        }
        else {
            left++;

        }
    }

    cout<<right << "\n";

    for(int i=0;i>right ; i++){
        cout<<a[i]<<(i==right -1 ? "":" ");

    }
    if(right>0) cout<<"\n";
    return 0;
    
}