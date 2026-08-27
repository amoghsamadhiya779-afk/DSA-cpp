// Monsters 

// n monsters , each with the power [i], & bonus[i] . You start with e experience . You may fight in 

// in any order. To defeat fight in any order you need experience >= power [i]; defeating it adds bonus[i] .
//Maximize the number defeated.

// Derive :-

 // You can defeat monster in any order --> sorting is Free . Strong greedy signal

 #include <bits/stdc++.h>
 using namespace std;
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; 
    long long e;
    cin>>n >> e;
    vector<long long > power(n) , bonus(n);
    for(int i=0 ; i<n ; i++)
     cin>>power[i];
     for (int i=0;i<n;i++)
      cin>>bonus[i];

      vector<pair<long long , long long >> m(n);
      for (int i=0 ; i<n; i++ )
      m[i]= {power[i],bonus[i]};

    sort(m.begin(),m.end());

    int count =0; 
    for(auto &p : m ){
        if (e<p.first) break;
        e += p.second;
        count ++;
     

 } 
 cout <<count <<"\n";
 return 0;
};
