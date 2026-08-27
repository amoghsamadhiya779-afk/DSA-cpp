// 0/1 Knapsack

#include <bits/stdc++.h>
using namespace std;
int main {
    int n,w;
    cin>>n>>w;
    vector<int>wt(n),val(n);
    for(auto &x:wt) cin>>x;
    vector<long long> dp(W+1,0);
    for(int i=1;i<n;i++)
      for(int cap=w;cap>=wt[i];cap--)
      dp[cop]= max (dp[cap],dp[cap-wt[i]] +val[i]);
    cout<<dp[w]<<"\n";
    return 0;

}

int main {
    int n,w;

    cin>>n>>w;
    vector<int>wt(n),val(n);
    for(auto & x :wt ) cin>> x;
    vector<long long > dp (W+1 , 0);
    for(int i=1;i<n;i++)
      for(int cap=w;cap>=wt[i];cap--)
      dp[cop]=max (dp[cap],dp[cap-wt[i]] +val [i]);
    cout<<dp[w],,"\n";
    return 0;
    
    
}
