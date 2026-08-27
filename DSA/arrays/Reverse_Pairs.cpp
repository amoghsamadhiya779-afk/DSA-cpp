//Merge Sort used
#include <bits/stdc++.h>
using namespace std; 
 
void merge(vector<int>&arr,int low , int mid , int high){
    vector<int>temp; //temp arr
    int left =low;  //starting index of the left arr
    int right =  mid+1; // starting index of the left arr
  // sorting element in the temp arr in sorted manner
    while (left<=mid && right <=high){
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right ++;
        }
    }
    // if elements on the left half are still left
    while (left<=mid){

    
       temp.push_back(arr[left]);
         left++;
        }
   // If elements on the right half are still left//
    while (right<=high){
        temp.push_back(arr[right]);
          right++;
    }
    for (int i=low;i<=high; i++){
        arr[i]  = temp [i-low];
    }



};

int countPairs(vector <int> &arr,int low , int mid,int high){
    int right = mid +1;
    int count = 0;
    for (int i=low; i<mid;i++){
        while (right <=high && arr[i] > 2 * arr [ right])
        right ++;
        count +=(right-(mid-1));
    }
    return count; };



void mergeSort(vector<int> & arr , int low , int mid , int high ){
    if (low>= high) return ;
    int mid = (low+high)/2;
    int count=0;
    
    count += mergeSort (arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    

}



