// Two sum in a sorted Array 


// Given a sorted array of n integer and a target return the two 0-based indices whose valyse sum to the target , or -1 if none exists.


//Opposing two Pointers.

//Clue "Sorted array"  +"Find a pair"


/*
Algorithm 

1.  L=0;  ,  r=n-1;

2 while l<r  ; compute sum=a[l]+a[r];

3  Sum ==target --> Answer Found . sum<target -> l++. 
 sum >target --> r--;

Loop exits --No pair found.
----------------------------------

Dry run 


a=[1,3,4,6,8,11]  ,target =10

l[0]= 1 , r[5]=11  sum =12 then r--

l[0] =1, r[4]=8  sum =9 then l++
l[1]=3,  r[4]=8  sum 11 then r--
l[1]=3  , r[3]=6   sum 9 then l++
l[2]=4 ,  r[3]=6  sum 10 ans (2,3)
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];


    sort(a.begin(),a.end());

    int l=0;
    int r=n-1;
    int ansL =-1 ;
    int ansR =-1;
    int target;
    cin>>target;

    while (l<r){
        long long sum ;
        sum = (long long) a[l] + (long long) a[r];
        
        if(sum==target){
            ansL=l;
            ansR=r;
            break;
        }
        else if (sum<target){
            r--;
        }
        else{ 
          l++;
        }

        }

        if (ansL=-1) cout<< -1<<"\n" ;

        else  cout<<ansL<<" "<<ansR <<"\n";
        return 0;

}



