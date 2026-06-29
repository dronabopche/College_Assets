class Solution:
    def isSubString(self, word:str , check_word:str) -> bool:
        n = len(word)
        m = len(check_word)

        if m > n:
            return False

        for i in range(n - m + 1):
            j = 0

            while j < m and word[i + j] == check_word[j]:
                j += 1

            if j == m:
                return True

        return False

    def numOfStrings(self, patterns: list[str], word: str) -> int:
        count = 0
        for i in range(len(patterns)):
            issub = self.isSubString(word, patterns[i])
            print(issub)
            if issub == True:
                count += 1

        return count