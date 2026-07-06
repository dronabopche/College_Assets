class Solution:
    def findLucky(self, arr: List[int]) -> int:
        freq = {} 

        for i in arr:
            if i in freq:
                freq[i] += 1
            else:
                freq[i] = 1
        ans = -1

        for i, j in freq.items():  
            if i == j:
                ans = max(ans, i)
                
        return ans
