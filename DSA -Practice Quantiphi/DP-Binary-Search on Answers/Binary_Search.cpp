/*Problem	State	Recurrence
Climbing Stairs	ways to reach step i	
dp[i] = dp[i-1] + dp[i-2]
Min Cost Climbing Stairs	min cost to reach i
p[i] = a[i] + min(dp[i-1], dp[i-2])
Kadane / Max Subarray	best subarray ending at i
cur = max(a[i], cur + a[i]); track global max
Coin Change (min coins)	min coins for amount x	
dp[x] = min(dp[x - c] + 1) over coins c
Coin Change II (count ways)	ways to make x	loop coins outer, amount inner:
dp[x] += dp[x-c]
0/1 Knapsack	best value with capacity w using first i	
dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i])
Unbounded Knapsack	same, item reusable	
dp[w] = max(dp[w], dp[w - wt[i]] + val[i]), amount ascending
LIS	LIS ending at i	
dp[i] = 1 + max(dp[j]) for j < i, a[j] < a[i]; O(n log n) via lower_bound on tails
LCS	LCS of prefixes i, j	
match → 1 + dp[i-1][j-1]; else max(dp[i-1][j], dp[i][j-1])
Grid Unique Paths	ways to reach (i,j)
dp[i][j] = dp[i-1][j] + dp[i][j-1]
Min Path Sum	min cost to (i,j)	
dp[i][j] = g[i][j] + min(dp[i-1][j], dp[i][j-1])*/



// A plain Binary Search 
int lowerbound (const vector<int> &a, int target){
    int lo =0; hi = (int)a.size();
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if (a[mid]>=target) hi=mid;
        else  lo = mid +1;



    }
    return low;

}



// Binary Search for answers

long long lo = <>
long long high= <>
long long ans =high;

while (low<=high){
    long long mid = lo+(hi-lo)/2;
    if(feasible(mid)){
        ans=mid;
        hi = mid -1;

    }
    else {
        lo = mid+1;

    }
}

// Allocate books / Split Array Largest Sum 


bool feasible (cont vector<long long> &a , long long limit , int k ){
    int parts =1;
    long long cur=0; 
    for(long long x: a){
        if (x>limit ) return false ;
        if (cur +x >limit)  { parts++; cur=x}
        else cur += x;

    }
    return parts <= k;

}

//Agressive Cow -- "Maximise the Minimum gap ", so the branch flips:

bool feasible (const vector<long long> &s, long long gap , int c){
    int placed =1;
    long long last =s[0];
    for(size_t i=1;i<s.size();i++){
        if (s[i]-last >= gap ){
            placed ++ ; last =s[i];
        }

    }
    return placed>=c;
}