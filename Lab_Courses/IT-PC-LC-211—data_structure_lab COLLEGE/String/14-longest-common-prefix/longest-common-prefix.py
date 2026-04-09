class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs: 
            return ""
        
        first = strs[0]
        ans = ""
        
        for i in range(len(first)):
            current_char = first[i]
            
            for s in strs[1:]:  
                if i >= len(s) or s[i] != current_char:
                    return ans
            
            ans += current_char
        
        return ans