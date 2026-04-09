class Solution:
    def repeatedCharacter(self, s: str) -> str:
        uq = set()

        for char in s:
            if char in uq:
                return char
            else:
                uq.add(char)