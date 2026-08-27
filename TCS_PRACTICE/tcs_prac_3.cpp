// Coin change -------DP
 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, amount ;
    cin>> n>>amount;
    vector<int> coins(n);
    for(auto & c: coins) cin>>c;
    const int INF =1e9;
    vector<int> dp(amount +1,INF);

    dp[0]=0;
    for(int v=1;v<=amount;v++)
    for (int c :coins)
     if(c<=v && dp[v-c]+1 <dp[v])
       dp[v]= dp[v-c]+1;
    cout<<(dp[amount]>=INF ? -1 :dp[amount])<<"\n";

    return 0;


}

int main() {
    int n,amount;
    cin>> n>> amount;
    vector<int> coins(n);
    for(auto &c :coins) cin>>c;
    const int INF =1e9;
    vector<int>dp(amount+1,INF);

    dp[0]=0;
    for(int v=1; v<=amount; v++)
     for (c<=v && dp[v-c]+1 <dp[v])
       dp[v] =dp[v-c] +1;
    cout<<(dp[amount]>=INF ? -1:dp[amount])<<"\n";

    return 0;


}