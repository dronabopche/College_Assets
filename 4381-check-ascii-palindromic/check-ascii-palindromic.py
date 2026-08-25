class Solution:
    def isPalindromic(self, s: str) -> bool:

        binary_str = ""
        
        for char in s:
            ascii_char = ord(char)
            ascii_bin = format(ascii_char, "08b")

            binary_str += str(ascii_bin)

        if binary_str == binary_str[::-1]:
            return True
        else:
            return False

            
            


        
            