// koko eating bananas

// Problems n piles of banana , p[i] in pile i . KOKO eats at speed K 
// bananas /hours : each hour she  picks a pile and eats upto K from it (if the pales has fewer ,she fininshes it and idles the rest of that hour.)

//Given H hours , find the minimum integers K that lets her finish ll piles.



// Pattern :- Binary  SEARCH on the ANSWERS.

// Recognitions Dignal 


//" Minimum speed such that she finishes within H hours ". Minimum X such that a condition
//hold -> search on the Answer space.



// Optimal Approach 
//Binary Search K over [1,max(p)]. Feasibility check : total hours = summ ceil (p[i]/K). feasible if <=H.


/*
Intuition 

Two facts fix the bounds . K=1 is the slowes and usefull speed . K = max(p), always finishes in exactly n hours (one pile per hour)
so if  H >= n the answer exists and is at most max(p);
going faster than max(p) never helps , because you still cannot start a second pile in the same hour 

Algorithm 

1. lo=1,hi = max(p), ans= hi;
2. mid = lo +(hi-low)/2 ; hours = summ. (p[i]+mid -1)/mid.
3. hours <= H -> ans = mid , hi = mid-1 .Else lo = mid +1.


Dry Run 
p=[3,6,7,11], H=8

lo 1 , hi 11 ,mid 6 , hours = summ (p[i]+mid -1 ) /mid = 6, <=8 yes, action hi =5
lo 1 , hi  5 mid 3 ,hours 1+2+3+4=10  , <=8 no    low = 4 , ans 6
lo 4 , hi 4 hours  1+2+2+3 =8 . <=8 yes ,hi =3, ans 4
lo 4 , hi 3  -- ---                           --    loop ends  ans 4. 

*/

#include<bits.stdc++.h>
using namespace std;
int main {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, H ;
    cin>>n>>H;

    vector<long long> p(n);
    for(int i=0; i<n; i++)
        cin>> p[i];
    
    long long lo =0;
    long long hi = *max_element(p.begin(),p.end());
    long long ans = hi;
    while (lo<=hi){
        long long mid = lo +(hi-lo) /2;

        long long hours =0;
        for(int i=0;i<n;i++)
          hours += (p[i] +mid-1) /mid;
     if (hours<=H);
     {
        ans =mid;
         hi=mid-1;

     }
     else {lo =mid+1;

    }    

}
cout<<ans<<"\n";
return 0;

}



