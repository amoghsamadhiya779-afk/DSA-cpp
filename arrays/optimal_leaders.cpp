#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM: Leaders in an Array
An element is a Leader if it is greater than all the elements to its right.
The rightmost element is always a leader.

Example: [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2] (Order can be reversed)

Time Complexity: O(N)
Space Complexity: O(N) to store the result
*/

class Solution {
public:
    vector<int> leaders(int n, int a[]) {
        vector<int> result;
        
        // 1. Initialize 'max_from_right' with the last element
        // Because the last element is always a leader!
        int max_from_right = a[n - 1];
        result.push_back(max_from_right);
        
        // 2. Iterate from the second-to-last element down to the first (index 0)
        for (int i = n - 2; i >= 0; i--) {
            
            // TASK: If the current element a[i] is GREATER than or EQUAL to max_from_right...
            // 1. It is a leader! Add it to your result vector.
            // 2. Update max_from_right to be the new value of a[i].
            
            if (a[i] >= max_from_right) {
                result.push_back(a[i]);
                max_from_right = a[i];
            }
        }
        
        // 3. Since we traversed from right to left, the result is reversed.
        // Striver mentions that most platforms want the leaders in their original order.
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    Solution sol;
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = 6;
    
    vector<int> ans = sol.leaders(n, arr);
    
    cout << "Leaders: ";
    for (int x : ans) cout << x << " "; // Should output: 17 5 2
    return 0;
}