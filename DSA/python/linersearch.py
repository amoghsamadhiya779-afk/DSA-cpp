def linear_search(arr,k):
    for i in range(len(arr)):
        if arr[i]==k:
            return i
    return -1
    

nums=[10,20,30,50]
k= 40

if linear_search(nums,k)==-1:
    print("not found")
else:
    print(f"found the target at index {linear_search(nums, k)}")
