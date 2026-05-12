class Solution:
    def concatWithReverse(self, nums: list[int]) -> list[int]:
        res=nums
        k=nums[::-1]
        return res+k