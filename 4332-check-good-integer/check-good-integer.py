class Solution:
    def checkGoodInteger(self, n: int) -> bool:
        arr_n = [int(d) for d in str(n)]
        digitSum = 0
        squareSum = 0

        for i in range(len(arr_n)):
            digitSum += arr_n[i]
            squareSum += arr_n[i]*arr_n[i]

        if squareSum - digitSum >= 50:
            return True
        else:
            return False