// 3SUM

// Fix one ,two - pointer the rest . The pattern of every K -sum.

// Find all unique triplets summing to 0. Output the count , them each triplet.
// in non - decreasing order , lexicographically sorted.
// The algebric move  a+b+c=0 <==> b+c = -a . Fix a , and you have a sorted- Two sum with -a as target .

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_main :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<long long > a(n);
    for(int i=0;i<n;i++)
    cin>> a[i];

    sort(a.begin(), a.end());
    vector<array<long long ,3>> res;

    for(int i=0; i+2 < n  ; i++){
        if(i>0 && a[i]==a[i-1])
        continue;

        long long target  = -a[i];
        int l =i+1, r = n-1;

        while (l<r){
            long long sum =a[l] +a[r];
            if(sum <target) l++;
            else if (sum>target) r--;
            else {
                res.push_back({a[i],a[l],a[r]});
                long long lv =a[i], rv=a[r];
                while (l < r && a[l] ==lv) l++;
                while(l<r && a[r] == rv )r--;
            }
        }
    }
    cout<<res.size()<<"\n";
    for(auto & it :res)
    cout<< t[0]<<" "<<t[1]<<" "<<t[2]<<"\n";

    return 0;


}


