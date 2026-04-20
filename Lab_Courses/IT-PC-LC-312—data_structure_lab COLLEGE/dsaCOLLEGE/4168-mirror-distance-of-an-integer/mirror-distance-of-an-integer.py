class Solution:
    def mirrorDistance(self, n: int) -> int:
        n_rev = int(str(n)[::-1])
        return abs(n_rev - n)