// HOUSES form a binary / general tree rooted at node 1, You cannot rob a node and its direct
  //child . Maximize the Total

  //Pattern 
  // Tree DP --- post Order DFS returning a pair of States

  // Recognition Signal 

  //The adjacency constraints appies along tree edges instead of array indices. "No tow Directly Connected",

  //Cannot pick a node and it's parent



  // Intuition

  //The array recurrence generalises cleanly .Each node returns two answers to its Parent:
  /*
  > rob[u] =best for u's subtree when u is robbed = val[u]+ summ skip[child]
  > skip[u]  = best for the u's subtree when u is not robbed = summ max(rob[child], skip[child])

  ======================================================

  Dry RUN


  Dry Run 

  5 ndoes value [3,2,3,3,1], edges 1-2 ,1-3,2-4,3-5.
*/

#include <bits/stdc++.h>
using namespace std ; 
int n;
vector<vector<int>> adj;
vector<long long >val;

pair<long long , long long > dfs (int u , int parent){
  long long rob =val[u];
  long long skip = 0;

  for(int v :adj[u]){
    if(v==parent ) continue;
    pair<long long ,long long>child =dfs(v,u);
    rob +=child.second;
    skip +=max(child.first, child.second);

  }

  return {rob,skip};

}

int main(){
ios_base :: sync_with_stdio(false);
cin.tie(NULL);

cin>> n;
val.assign(n+1,0);
adj.assign(n+1,{});

for(int i=1;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);

}

pair <<long long , long lo g >res =dfs(1,0);
cout<<max(res.first,res.second)<<"\n";
return 0;

}