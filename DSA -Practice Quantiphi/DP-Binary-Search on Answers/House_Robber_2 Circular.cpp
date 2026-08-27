
//  Similar problem , but the houses form a circle -- house 0 and house n-1 are adjacent .

//Pattern   :- Linear DP appied twice with a case split

// Recognition Signal 

// The Word circular , "in a ring ", wraps around 
// or First and Last Are neighbours .

//Optimal Approach 

//Break the Circle by case-splitting  on house 0, Either you rob house 0 or you dont
// if you rob house 0, house n-1 is forbidden -> Solve liner House Robber on a[0...n-2]

//If you do not rob house 0 , house n-1 is free -> solve linear on a[1 .... n-1]

// The answers is the max of both sub ranges.


/*
Algorithm :

1. If n==1, answer is a[0]
Ans = max(roblinear (a,0,n-2),robliner(a,1,n-1)).

=======================================================

Dry run . 
a=[1,2,3,1]
Range [0..2]=[1,2,3]:
a[0]=1 ,prev2 =0, prev1=0, cur=1
a[1]=2 ,prev2 =0, prev1 =1, cur = max (2,1)=2
a[2]=3 , prec 2, =1 , prev1 =2 max (4,2)=1 4

Range [1....3] = [2,3,1]
a[1]=2 , prev2=0 , prev1=0, cur =2
a[2]=3 ,prev2=0 , prev1 =2 , cur= max(3,2) =3
a[3]=1  ,prev2 =2 , prev1=3  cur =max(3,3)=3


Answer max(4,3)   houses 0, and 2

*/




#include <bits/stdc++.h>
using namespace std ;
  long long roblinear (vector<long long > &a, int hi , int lo){
  long long prev2 =0, prev1=0;
  for(int i=lo i<=hi;i++){
    long long cur =max (prev2+a[i],prev1);
    prev2=prev1;
    prev1=cur;

  }
  return prev1;
  }
int main(){

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<long long > a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    if(n==0){cout<<0<<"\n";return 0;}
    if(n==1){cout<<a[0]<<"\n"; return 0};
    long long best =max(roblinear(a,0,n-2),roblinear(a,1,n-1));

    cout<<best <<"\n";

    return 0;



}
   

