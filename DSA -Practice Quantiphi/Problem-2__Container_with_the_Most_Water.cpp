// Opposing Two pointer With a greedy Approach n vertical lines ,Heights h[0,1,2,3,...n-1],lines i at x-coordinate i.


// "Maximum area"  / MAXIMUM OVER ALL PAIRS (i,j)

//Where the value is (j-i)*min(h[i],h[j]).

// Optimal approach Wildest Container First  (l=1, r=n-1)


// Area is width* min(h[l],h[r]).Suppose h[l]<h[r]

/*
Algorithm 

1. l=0 , r=n-1 , best =0. 
2. While l<r :area =(r-1) * min(h[l],h[r]); best = max(best, area)
3. h[l],h[r]  --> l++  else r--.

------------------------------------------- 


l[0]= 1 , r[8]=7  width =8, min =1 , area =8  best =8   l++(1<7)

l[1]=8 , r[8]=7   width =7, min =7 , area =49  best 49  r--(8>=7)

l[1]=8 , r[7]=3   , width =6  min =3  area =18 , best 49 , r-- (8>3)

l[1]=8, r[6]=8   , width =6  min= 8 area =40 , best=49   , r-- 
..
..


..

l[1]  r[1]   - - - - - -- - -- -  loop ends 



Ans =49



*/


#include <bits/stdc++.h>
using namesapce std;

int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];


    int l=0;
    int r=n-1;
    long long best =0;

    while(l<r){
        long long width =r-1;
        long long height= min(a[l],a[r]);
        best =max(best, wigth* height);

        if(l<r)  l++;
        else r--;


    }

    cout<<best<< "\n";
    return 0; 

    


}