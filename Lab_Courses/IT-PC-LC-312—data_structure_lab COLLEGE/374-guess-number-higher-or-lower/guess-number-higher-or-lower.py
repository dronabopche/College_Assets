class Solution:
    def guessNumber(self, n: int, low=1, high=None) -> int:
        if high is None:
            high = n

        curr_num = (low + high) // 2

        if guess(curr_num) == 1:
            return self.guessNumber(n, curr_num + 1, high)

        elif guess(curr_num) == -1:
            return self.guessNumber(n, low, curr_num - 1)

        else:
            return curr_num