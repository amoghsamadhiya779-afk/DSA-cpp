//Modular exponentiation fast power 

#include <bits/stdc++.h>
using namespace std;

long long power (long long a, long long b, long long mod){
    long long res=1;
    a% =mod;
    while (b>0){
        if(b&1) res =res * a % mod;
        a=a*a %mod;
        b>>1;
    }
    return res;

}

int main(){
    long long a,b,m;
    cin>> a>>b>>m;
    cout<<power(a,b,m)<<"\n";
    return 0;

}


long long power (long long a , long long b , long long mod){
    long long res =1;
    a% =mod;
    while(b>0){
        if(b&1) res = res * a % mod;
        a=a*a %mod;
        b>>1;
    }

    return res;

}

int main(){
    long long a,b,m;
    cin>>a>>b>>m;
    cout<<power(a,b,m)<<"\n";
    return 0;

}