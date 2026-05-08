class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        ans = 0
        count = 1
        
        if len(nums)==1:
            return 1
        else:
            for i in range(1,len(nums)):
                if nums[i-1] < nums[i]:
                    count+=1
                else:
                    count=1
                ans = max(ans,count)

        return ans