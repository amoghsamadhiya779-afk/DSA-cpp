def linear_Search(arr,k):
    count =0
    for i in arr:
        if i==k:
             count +=1
    return count

    

arr=[1,2,3,4,5,5,4,5]
k=5
x=linear_Search(arr,k)
print(x)
