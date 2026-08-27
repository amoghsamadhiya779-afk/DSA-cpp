// An  m*n grid of'1' (land) and '0' (water) . Count the islands ;
//Island connects 4-Directionally.


// Pattern:- Grid DFS /Flood Fill - connected on an implicit graph.

//Recognition Signal 

// Count regions /group / clusters , "connected components ", a grid where neighbours are implicitly


// Algorith m

//1. count =0.
//2 . For each cell :if it is '1', count ++ and DFS from it , sinking every reachable land
// 3. DFS bound -checks , bail if not '1' , set to '0'
// recurse in 4 directions.

#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<string> g;
dfs(int r, int c){
    if(r<0 ||r>=m ||c<0 ||c>=n) return ;
    if(g[r][c]!='1') return ;
    g[r][c] ='0';

    dfs(r+1,c);
    dfs(r-1,c);
    dfs(r,c+1);
    dfs(r,c-1);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;
    g.resize(m);
    for (int i=0 i<m;i++) g[i];
    int count =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='1'){
                count ++ ;
                dfs(i,j);

            }
        }
    }

    cout<<count <<"\n";
    return 0;
    
}