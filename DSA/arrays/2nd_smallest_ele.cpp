#include <bits/stdc++.h>
using namespace std;
int Second_Smallest(vector<int>&a,int n){
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i=1;i<n;i++){
        if (a[i]<smallest){
            smallest = a[i];
        }
        else if (a[i]!= smallest && a[i] <smallest){
            ssmallest =a[i];
        }
    }
    return ssmallest;
    
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    int n = arr.size();
    int sS = Second_Smallest(arr, n);
    
    cout << "The second smallest element is: " << sS << endl;

    return 0;

}