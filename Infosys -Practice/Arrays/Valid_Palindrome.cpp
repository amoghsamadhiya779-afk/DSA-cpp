// When s[L] !=s[R]  , you have hit a roadblock . You must use your lifeline right , then and there 

// We have two choices :

//1.  Delete the left character (simulate by checking if( a[L+1 .... R]) is a perfect palindrome).
//2. Delete the right character (simulate by checking if a(L.... R-1) is a perfect palindrome).

// If either remaining inner substring is a perfect palindrome , the whole string is valid.

#include <bits/stdc++.h>
using namespace std;
 bool isPalindromeRange(const string& s  , int l , int r){
    while(l<r){
        if(s[l] != s[r])
        return false;
        l++;
        r--;


    }
    return true;
 }
int main()


{ ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    int l =0 , r=s.length()-1;

    while (l < r){
        if (s[l] != s[r])
        {
            //Mismatch found We use our ONE LIFE LINE 

            if (isPalindromeRange(s,l+1,r) || isPalindromeRage(s,l,r-1))
            {

            
            cout<< "yes \n";


            
        }  else {
            cout<<"No\n";
        }
        return 0;


        
    }

    l++;
    r--;


    }
   cout<<"YES\n";
   return 0; 
 }