class Solution:
    def maxPairStrength(self, nums: list[int]) -> int:
        n = len(nums)
        max_val = 0
        for i in range(n):
            for j in range(i+1,n):
                max_val = max(max_val,int((nums[i]*nums[j]) / (gcd(nums[i],nums[j]))**2))
        return max_val