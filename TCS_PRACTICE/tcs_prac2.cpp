//  Longest Substring without repeating characters --- Sliding Window.

#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
vector<int> last(256,-1);
int best =0,left=0;

for (int right =0;right <(int)s.size();right++)
  if(last[s[right]]>=left)
    left =last[s[right]]+1;
    last[s[right]]=right;
    best = max(best,right-left -1);
    
}
cout<<best<<"\n";
return 0;

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int>last (256.-1);
    int best =0 ,left =0;

    for (int right =0; right <(int) s.size();right++ )
    if(last [s[right]>=left])
      left =last[s[right]]+1;
    best = max(best,right -left -1);


}


cout <<best<<"\n";
return 0;
