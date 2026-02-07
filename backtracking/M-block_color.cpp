#include <bits/stdc++.h>
using namespace std;
class Solution{
    bool isSafe(int node, int color[],bool graph[101][101],int n,int col){
        for (int k =0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return false;
            }
        }
        return true;
    }
    bool solve (int node ,int color[],int m ,int N,bool graph[101][101]){
        if(node ==N){
            return true;
        }

        for(int i=1;i<=m;i++){
            if(isSafe(node,color,graph,N,i)) {
                color[node]=i;
                if(solve(node+1,color,m,N,graph)) return true;
                color[node]=0;
            }
        }
        return false;
    }

public:
    bool graphColoring(bool graph[101][101], int m, int N) {
        int color[101]={0};
        if(solve(0,color,m,N,graph)) return true;
        return false;
    }
};

int main() {
    int N = 4; // Number of nodes
    int m = 3; // Number of colors
    bool graph[101][101] = {0};

    // Creating a simple graph (Square with one diagonal)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;

    Solution sol;
    if (sol.graphColoring(graph, m, N))
        cout << "Possibility of coloring: Yes" << endl;
    else
        cout << "Possibility of coloring: No" << endl;
    return 0;
}