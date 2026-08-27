#include <bits/stdc++.h>
using namespace std;
 vector <int> rotateArray(vector<int>&arr,int n)
 {
    int temp = arr[0];
     for (int i=1;i<n;i++){
        arr[i-1]=arr[i];


     }
     arr[n-1]=temp;
     return arr;
 }

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    
    vector<int> result = rotateArray(arr, n);
    
    cout << "Array after left rotation: ";
    for(int i : result) cout << i << " ";
    cout << endl;

    return 0;
}