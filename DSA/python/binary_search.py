def Binary_Search(arr,j):
    low=0
    high= len(arr)-1
    ans=-1
    while low<=high:
        mid=(low+high)//2
        if arr[mid]==j:
         ans=mid
         break 
        
        elif arr[mid]<j:
          low=mid+1
        else:
          high = mid-1
    return ans

list=[10,20,30,40]
k=30
if Binary_Search(list,k) == -1:
 print ("not found")
else:
   print("found") 


       