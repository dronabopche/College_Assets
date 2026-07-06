class Solution:
    def findLucky(self, arr: List[int]) -> int:
        arr.sort() 
        
        curr = arr[-1]
        count = 0
        
        #backwards
        for i in arr[::-1]:
            if i == curr:
                count += 1
            else:
                #check the group we counting
                if curr == count:
                    return curr
                
                # Reset
                curr = i
                count = 1  
        
        if curr == count:
            return curr
            
        return -1
