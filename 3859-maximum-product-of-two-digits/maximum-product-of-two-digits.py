class Solution:
    def maxProduct(self, n: int) -> int:
        num = str(n)
        curr_max = 0
        sec = 0

        for i in num:
            no = int(i)
            if no >= curr_max:
                sec = curr_max
                curr_max = no
            elif no > sec:
                sec = no

        return sec * curr_max