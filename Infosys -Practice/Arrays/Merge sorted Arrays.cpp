//  Algorithm    1. Initialise 3 pointers :

// p1 = m-1 (pionts to the last actual number in a)
//  p2 = n-1 (points to the last number in b )

// p = m+n-1 (points to the very  end of a , our write position)

// While both p1 >= 0 and p2>= 0 :

// Compare a[p1]  and b[p2].

// Write the larger of the two into a[p].

// Decrement p  and whichever pointer (p1 or p2)

#include <bits/stdc++.h>
using namespace std;
 int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int m , n;
    cin>> m >> n ;
    vector<long long > a(m+n);
    for(int i=0; i<m+n;i++){
        cin>>a[i];}
        vector<long long > b(n);
        for(int i=0; i<n ; i++)
        cin>>b[i];

        int p1 =m-1;
        int p2 = n-1;
        int p = m+n -1 ; 
        while(p1>=0 && p2 >= 0){
            if(a[p1] > b[p2]){
                a[p] =a[p1]; 
                p1--;

            }else{
                a[p] = b[p2];
                p2--;

            }

            p--;

        }
     for(int i = 0 ; i<m+n -1 ;i++){
        cout<< a[i] <<(i== m+n-1 ? "" : " ");

     }
     cout<<"\n";
     return 0;
     
    
 }