//  Pattern :- Variable -size sliding window with last seen index.


// Signal :-longest contiguous substring /subarry such that" --> variable sliding window.

//  the Window maintain the [left , right]

 // When s[right].. so left [jumps] to last[c]+1.

 // main condition last[c]>=last is the crux


 /*
 Algorithm 

 1. last [256]  initialised to -1; left =0;
 best =0.

 2. For right =0..... n-1, let c=s[right].

 3. If last[c] >=left .set left =last[c]+1.
 4.last[c] =right . 

 5. best =max(best , right -left +1)
 */


 #include <bits/stdc++.h>
 using namespace std;
  int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s ;
    if(!getline (cin,s)) return 0;
    vector<int> last (256,-1);
    int left =0;
    int best =0;
    for(int right =0; right <(int)s.size();right++){
        unsigned char c =s[right];
        if(last[c] >= left) left= last [c] +1;
      last [c] =right;
      best =max(best, right -left +1);
      
    } 
    cout<< best <<"\n";
    return 0;



}