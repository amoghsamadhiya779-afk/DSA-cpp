/*
Problem . Sorted arraY . Remove deuplicates in plan so each valuse appears once. 
Print the new length.

Decode . "In place -> Same - direction . Output = lenght +prefix of array .Sorted means"

Intuition . Two roles . slow is the write position ( last index of the answer so far), fast is the read scanner . 
Every  time fast  finds soething different from a[slow], it's  new -- 
advance slow and write it there . The answer is always built in the prefix [0,slow], so we never overwrite anything we still need.




*/

#include<bits/stdc++.h>
using namespace std;
int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n; i++)
    cin>>a[i];
    if(n==0){
        cout<<0<<"\n"; return 0;


    }
    int slow =0;
    for(int fast =1; fast <n; fast++){
        if (a[fast]!=a[slow]){
            slow++;
            a[slow]=a[fast];

        }
    }

    int len =slow +1;
    cout<<len<<"\n";
    for(int i=0; i<len;i++)
    cout a[i] (i+1 <len ? ' ' : '\n');
    return 0;
    
}
