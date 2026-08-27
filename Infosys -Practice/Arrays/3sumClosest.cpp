// "Heat Seeking Missiles "
//You appraoch this identically to the standard 3SUM problem

// and dispatch a Search Pary (L and R) to look through the Remaining elements.

// The difference here is that you act like a heat seeking missle tracking a target signature.

// Every time you calculate a current_sum , you measure it's Distance to the target using 

//absolute differnce  : abs(current_sum - target).

// if the  Disdance is smaller than your closest_sum's distance, you overwrite your record . 

// The golden rule for movin : Because the Array is sorted , if (current_sum < target , the only way to "Warm up " is to move L++ . )

//current_sum >target , the only way to "cool dowm " is to move R--;

// THe Early exit : If (current_sum == target , the distance is 0. You can immediately print and exit , This small optimisation.)

// show s mastery in technical interviews.

#include  <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    long long target;
    cin>>n>>target 
    vector<long long > a(n);
    for(int i==0 ; i<n; i++){
        cin>>a[i];
    }

    sort (a.begin(), a.end());
    long long closest_sum = 1e18;
    for (int i=0; i<n-2; i++){
        int l = i+1;
        int r = n-1;

        while (l<r){
            long long current_sum = a[i]+a[l]+a[r];

            if (abs(current_sum -target) <abs(closest_sum-target)){
                closest_sum = current_sum;
            }
            if (current_sum <target){
                l++;

            }
            else if (current_sum > target){
                r--;

            }else{
                cout<<current_sum <<"\n";
                return 0;
            }
        }
    }
    cout<<closest_sum<< "\n";
    return 0 ;
    

}