
class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        res = 0
        for n in nums:
            res = n ^ res  
        return res


nums = [4, 1, 2, 1, 2]
solution = Solution()  
single_number = solution.singleNumber(nums)  
print("The single number in the array is:", single_number)