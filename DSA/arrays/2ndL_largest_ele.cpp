#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>&a,int n){
    int largest = a[0];
    int slargest = -1;
    for (int i=1;i<n;i++){
        if (a[i] > largest){
            slargest = largest;
            largest =a[i];
        }
        else if (a[i]< largest && a[i]> slargest){
            slargest=a[i];
        }    
        
    }
    return slargest;
    
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    int n = arr.size();
    int sL = secondLargest(arr, n);
    
    cout << "The second largest element is: " << sL << endl;

    return 0;

}