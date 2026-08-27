#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s ;
    cin>>s;

    int freq[26] ={0};

    for(char c:s) freq[c-'a']++;

    char ans ='#';
    for (char c: s){
        if (freq[c-'a']==1){
            ans = c;
            break;

        }

    }
    cout<<ans <<"\n";
    return 0;
    
}