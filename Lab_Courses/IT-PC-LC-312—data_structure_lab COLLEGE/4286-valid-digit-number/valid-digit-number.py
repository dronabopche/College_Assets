class Solution:
    def validDigit(self, n: int, x: int) -> bool:
        n = str(n)

        if int(n[0]) == x or len(n)==1:
            return False
        else:
            for i in range(1,len(n)):
                if int(n[i]) == x:
                    return True
            return False