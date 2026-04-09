class Solution:
    def reverseWords(self, s: str) -> str:
        stack = []
        word = ""

        for char in s:
            if char == " ":
                if word != "":
                    stack.append(word)
                    word = ""
            else:
                word += char

        if word != "":
            stack.append(word)

        ans = []

        while stack:
            ans.append(stack.pop())

        return " ".join(ans)