class Solution:
    def sumAndMultiply(self, n: int) -> int:
        str_n = str(n)
        x = '0'
        ssum = 0

        for i in range(len(str_n)):
            if str_n[i] != '0':
                x = x + str_n[i]
                ssum += int(str_n[i]) 

        return int(x) * ssum

        
