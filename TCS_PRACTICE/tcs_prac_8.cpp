//Sieve of Eratosthenes

#include <bits/stdc++.h>
using namespace std;
int main(){
    int N=10000000;
    vector<bool> isComposite(N+1,false);

    for(long long i=2;i<=N;i++)
      if(!isComposite[i])

       for(long long j=i;j<=N;j+=i)
       isComposite[j] true;

       int hi,lo,cnt=0;
       cin >>lo>>hi;
       for(int x =max(lo,2);x<=hi;x++)
        if (!isComposite [x]) cnt++;

        cout<<cnt<<"\n";
        return 0;

}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int N=10000000;
    vector<bool> isComposite(N+1,false);
    for(long long i=2;i<=N;i++)
      if(!isComposite[i])
    for(long long j=i;j<=N;j+=i)
     isComposite[j] true;
    int hi , lo ,cnt=0;
    cin>>lo>>hi;
    
    for(int x=max(lo,2);x<=hi;x++)
      if (!isComposite[x] ) cnt++;
      cout<<cnt<<"\n";
      return 0;
       
}