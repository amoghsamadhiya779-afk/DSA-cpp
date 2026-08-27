// Part 0 -- The Operation YOU must HAVE Automatic


/*
(x>>i) & i  // read bit i 
x | (1LL <<1)  // Set bit i
x & ~(1LL<< i)  //clear bit i
x ^ (1LL << i )  // Toggle bit i
x & (x-1) //clear the LOWEST set bit 
x &  (-x) // isolate the lowest set bit 

__builtin_popcountll(x) //count set bit
__builtin_clzll(x) // count leading zeros (careful : undefned for x == 0 )
63 -  __builtin_clzll(x) //  Index of the Highest set bit , for x>0;
x & 1 // is Odd


// Keyword Decode 
Words in Problem                          Signal
Appears Twice except one                  XOR the whole array 
Maximise /Minimize XOR over a range of x  per-bit greedy , high bit to low bit
Maximum XOR of a subset             DP over reachable XOR values , or linear basis
Maximum XOR of a pair               binary trie
Count subarrays   with XOR =K       prefix XOR + hash map (same shapeas prefix sum)
without using airthmetic operation       bit tricks 
power of two                              x>0 && (x & (x-1)) == 0
Subsets/all combinations , n<= 20       bitmask enumeration
(a&b) * 2<(a|b)                           see W4 -- this means different highest set bit
*/



// W1 - Xor- Sum 

/*The per-bit greedy . The official solution cannot pass it's own constraints -- it loops 0..K
where K<= 10 ^9


Problem . Array A of N elements and an integer K , Define Xor-sum(x) = (x^A[1])+(x^A[2])+(x^A[N]) . Find the Maximum 
Xor-Sum over x = [0,K].

Derive --- This is Consequence 2 in action . Look at one bit b . Let
 cnt[b]  =  how many A[i] have bit b set. 
 . If x has a bit b set, sense filp -> contribution (N -cnt[b] * 2^ b)

 So each bit is decided independently , set bit b iff N - cnt[b] > cnt [b] .Except that 
 x <= K couples the bits back together.

 Handling x<= K . Every x<K has a unique highest bit where it differs from K - and at that bit . 
 K has 1 and x has 0 . Above it they match ; below it x is completely free
 */  

#include <bits/stdc++.h>
using namespace std;

const int B =31;
long long valueOf(long long x, vector<long long >&cnt , long long n){
    long long total =0;
    for (int b=0; b<B;b++){
        long long c = ((x>>b) &1) ? (n-cnt[b]):cnt[b];
        total += c* (1LL<<b);

    }
    return total;

}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    long long n, K;
    cin>>n>>K;
    vector<long long > a(n);
    for (int i=0 ; i<n; i++) 
     cin>>a[i];
    vector<long long > cnt (B,0);
    for (long long v:a)
     for(int b=0; b<B; b++)
      if ((v>>b ) & 1) cnt[b]++;
    long long best = valueOf(K,cnt,n);
    
    for (int i=B-1; i>=0;i--){
        if(!((K>>i) & 1)) continue;
        long long x =(K>> (i+1)) <<(i+1);
        for(int b =i-1; b>=0; b--)
          if (n-cnt[b] >cnt[b])
           x|=(1LL<<b);
        best = max(best, valueOf(x,cnt , n));   

    }

    cout<< best<<"\n";
    return 0 ;

}