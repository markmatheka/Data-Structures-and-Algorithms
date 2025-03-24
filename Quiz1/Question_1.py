class RemoveDuplicates:
    def removeDuplicates(self, nums: list[int]) -> int:
        if not nums:
            return 0  
        unique_ptr = 1  

        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:  
                nums[unique_ptr] = nums[i]  
                unique_ptr += 1  

        return unique_ptr
    
nums = [1, 1, 2, 2, 3, 4, 4, 5, 5, 5]

remover = RemoveDuplicates()
new_length = remover.removeDuplicates(nums)

print("New length:", new_length)
print("Array after removing duplicates:", nums[:new_length])  