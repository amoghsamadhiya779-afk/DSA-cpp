#include <bits/stdc++.h>
using namespace std;

int linearsearch(int n, int num, vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        if (arr[i]==num){
            return i;
        }
    }
    return -1;
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int num = 4;
    int result = linearsearch(n, num, arr);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}