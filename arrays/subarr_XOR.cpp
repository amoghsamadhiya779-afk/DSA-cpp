#include <bits/stdc++.h>
using namespace std;
int subarrwithXORSUM_K(vector<int>a,int k){
    int xR=0;
    unordered_map<int,int>mpp;
    mpp[xR]++; //{0,1}
    int cnt =0;for (int i=0;i<a.size();i++){
        xR =xR^a[i];
        //k
        int x =xR^a[k];
        cnt +=mpp[x];
        mpp[xR]++;
    }
return cnt;
}