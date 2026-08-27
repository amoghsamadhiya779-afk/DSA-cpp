// House Robber Problem    -1

/* 
> Non - negative integers a[0.....n-1] represents money in house in a row . You cannot rob two

adjacent houses .OutPut the Maximum total .

Pattern Linear DP, O(1) space.


>>> Recognition Signal 

"Maximum sum , no two adjacent / cannot pick consecutive elements". Any Phrasing where 
a choice at i forbids a choice at i+1


####### OPTIMAL APPROACH
Sweep Left to the Rght Holding two rolling Values.



Intuition

prev1 =best answer for everything and including the house . 
prev2=best answer to the house before that .At each step the answer is "money here plus prev2"
versus "just prev1" . Then shift the Window forward.


Algorithm

1. prev2 =0, prev 1 =0.
2. For Each a[i] : cur =max(prev2 +a[i],prev1).
3. prev2=prev1, prev 1 = cur.
4. Answer is prev1.

===============================================

Dry Run 
a=[2,7,9,3,1]

a[0]=2 , prev2=0,prev1=0 , take(prev2+a[i]) = 2 , skip (prev1) =0  ,cur=2, new prev2 = 0 , new prev1= 2
a[1]=7,  prev2=0, prev1=2, take = 7 ,skip =2,cur =7, new prev2=2, new prev1 =7
a[2]=9, prev2 =2,prev1=7 take = 11 , skip=7, cur=11, new prev2 =7, new prev1=11
a[3]=3, prev2 =7,prev1=11 , take =10, skip = 11, cur=11, new prev2=11, new prev1=11
a[4]=1, prev2 =11, prev1=11 , take 12 , skip =11 curr=12 , new prev2=11 , newprev1=12
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin>>n;
    vector<long long> a(n);
    for(int i=0; i<n;i++)
     cin>>a[i];

    long long prev2 =0 ,prev1 =0
    for (int i=0, i <n; i++){
        long long take =prev2 +a[i];
        long long skip = prev1;
        long long cur = max(take,skip);
        prev2=prev1;
        prev1=cur;

    }  
    
    cout<<prev1<<"\n";
    return 0;
    
    
}




