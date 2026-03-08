#include <bits/stdc++.h>
using namespace std;

class SubarrayOptimizer{
    private:
    //This is where we hide the things from outside world

public:
long long  maxSubarray(int arr[],int n)
{
    long long sum =0 , maxi =LONG_MIN ;
    for (int i=0;i<n;i++){
        sum += arr[i];
        if (sum>maxi){
            maxi=sum;
        }

            if (sum<0){
                sum = 0;
            }
            

    }
    return maxi;
}

};

int main(){
    int arr[]= {-1,-2,-3,4,-5,-1,-2};

    int n = 6;

    SubarrayOptimizer myOptimizer;

    long long answer = myOptimizer.maxSubarray(arr,n);

    cout<<"The Maximum Subarray Sum is :"<<answer<<endl;
    return 0;
    
}