class Solution:
    def trap(self, height: List[int]) -> int:
        Lmax = Rmax = total = 0
        
        i = 0
        j = len(height)-1

        while ( i < j):
            if ( height[i] <= height[j]):
                if Lmax > height[i]:
                    total += Lmax - height[i]
                else:
                    Lmax = height[i]

                i += 1
            else:
                if Rmax > height[j]:
                    total += Rmax - height[j]
                else:
                    Rmax = height[j]
                j -= 1

        return total