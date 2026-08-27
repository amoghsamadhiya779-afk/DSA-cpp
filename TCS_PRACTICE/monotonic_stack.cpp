//Monotonic Stack -Next Greater Element 

#include <bits/stdc++.h>
using namespace std;
int main (){
    int n ; 
    cin>>n;
    vector<long long> a(n), ans(n,-1);
    for(auto &x :a) cin>>x;
    stack <int>st;
    for(int i=0; i<n;i++){
        while (!st.empty() &a[i]>a[st.top()]){
            ans[st.top()]=a[i];
            st.pop();
        }
        st.push(i);

    }

    for (int i = 0;i<n;i++) cout<<ans[i]<<"\n"[i==n-1];
    return 0;


}

