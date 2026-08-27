// Words in the problem                     //Signal
// anagram / Same letters reaaranged      // frequency array comparision, not sorting

// first .. that appears once / unique    // frequency array, two pases

// palindrome                             // two pointers from both ends 

//ignoring case/non-alphanumeric/spaces   // clean / normalise first , then two pointers

//in place                                // mutate the string / char-array, directly , O(1) extra space
 
//compress / run-length                   //  single pass, track run start and length

//common prefix accross multiple strings  // compare column - by-column , or pairwise reduce

//reverse words                           // split logic - different from simple reversal

//permutation of a pattern exists in text //fixed - size sliding window +frequency match

//distinct characters                     // frequesncy array or a set

// substring /contains                    // sliding window , or find() if brute force is acceptable.



/*
=============================================================================

Valid Anagrams

The foundational problem for the frequency -array pattern . 
Problem :- Given two strings , determine if the second is an anagram of the first.
Decode :- Output = boolean . "ANAGRAM "  - > smae letter multiset , order irrelevant . 
Constraint doesn't matter here -- even at n=10^5 , this is trivially O(n).

Why not sort and compare ?? Sorting both strings and checking equaltiy also works but it's O(nlog n)
A frequency array is O(n) and is the technique the rest of this tier depends on -- learn it here. 

Intuition . If two strings are anagrams , incrrmenting counts, for one and decrementing 
for the other must return every counter to exactly zero , Thast single array servers as the entire comparison
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;

    cin>>s1>>s2;

    if(s1.size() != s2.size()){
        cout<<"NO \n"; return 0;


    }

    int freq[26]={0};
    for(char c : s1) 
    freq [c-'a'] ++;

    for(char c:s2) freq[c-'a']--;
    for(char c:s1) freq[c-'a']++;

    bool pl = true;

    for (int i=0 ; i<26; i++)
    if (freq[i] != 0 ){
        ok false ; 
        break;

    }
    cout<<(ok ? "YES" ::"NO")<<"\n";

    return 0;
    


}