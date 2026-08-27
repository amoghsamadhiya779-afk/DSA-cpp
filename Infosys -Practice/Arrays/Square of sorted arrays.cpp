#include <bits/stdc++.h>
using namespace std ; 
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);


    int n ;
    cin>>n ; 
    vector<long long> a(n);
    for (int i=0; i<n ; i++)
    cin>>a[i];
     
     vector <long long > result(n);
     int left =0;
     int right n-1;

     for(int i=n-1 ; i>=0 ; i--){
        long long left_sq = a[left] * a[left];
        long long right_sq= a[right]* a[right];

        if(left_sq>right_sq){
            result[i]=left_sq;
            left ++;

        }
        else{ result[i] =right_sq;
            right --;
       }    
    }
    for (int i=0; i<n; i++){
        cout<<result[i]<<(i==n-1 ? " " : " ");
        cout<<"\n";

        return 0;
        
    }
}


