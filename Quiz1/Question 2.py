def rotate(nums,k):
    k=k%len(nums)
    nums[:]=nums[-k:]+nums[:-k]

k=2
nums=[1,2,3,4,5]
rotate(nums,k)
print(nums)    