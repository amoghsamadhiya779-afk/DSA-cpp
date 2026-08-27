//  Given an array of n positive integer and target S  , find the minimal length of the constigous
// Subarray whose sum is >= S . Output 0 if none exists. 


// Constraints : 1<n <10^5,

// Algorithm 
/*
1.)left =0 , sum =0, bet =INT_MAX 

2.)For right from 0 to n-1 : sum +=a[right]

3.)While sum>= S : record best =min(best ,right -left +1) ; then 
sum-=a[left]; left++
4.) Answer is best , or if Best wasnever updated . 
*/


#include <bits/stdc++.h>
using namespace std; 
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
     

    int n ;
    long long S;
    cin>>n>>S;


    vector<long long > a(n);
    for(int i=0;i<n;i++) 
    cin>> a[i];
    int left =0;
    long long sum =0=;
    int best =INT_MAX;

    for(int right =0;right <n; right ++){
        sum += a[right];
        while(sum>=S){
            best = min(best,right-left+1);
            sum-=a[left];
            left++;

        }
        
    }

    cout<< (best == INT_MAX ? 0 :best ) <<"\n";

    return 0;
    


}