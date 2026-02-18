#include <bits/stdc++.h>
using namespace std;
 int largest_Element(vector<int>&arr,int n){
    int largest=arr[0];
    for (int i=0;i<n;i++){
    if (arr[i]>largest){
        largest=arr[i];
    }
 }
    return largest;
};

    int main() {
    vector<int> arr = {3, 2, 1, 5, 2};
    int n = arr.size();
    int max_element = largest_Element(arr, n);
    cout << "The largest element in the array is: " << max_element << endl;
    return 0;
}

