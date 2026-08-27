//Brute force


# include <bits/stdc++.h>
using namespace std;
 vector<int>moveZeros(int n,vector<int> a){
    //step -1

    vector<int>temp;
    for (int i=0;i<n;i++){
        if (a[i] !=0){
            temp.push_back(a[i]);
        }
    }
    //step-2

    int nz =temp.size();
    for (int i=nz;i<n;i++){
        a[i]=temp[i];

    }
    // step 3
    for (int i =nz ;i<n;i++){
        a[i]=0;
    }
    return  a;
 }

 // Optimised code


 #include <bits/stdc++.h>
 using namespace std;

 vector<int>moveZeros(int n ,vector<int>a){
    int j= -1;
    for (int i=0;i<n;i++){
        if (a[i]==0){
            j=i;
            break;
        }

    }

    //for non zero numbers
    if (j==-1){
        return a;
         for (int i=j+1;i<n;i++){
            if (a[i]!=0){
                swap (a[i],a[j]);

            }
         } 

         return a;
    }
 };
