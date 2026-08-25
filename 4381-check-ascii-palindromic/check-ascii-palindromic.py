class Solution:
    def isPalindromic(self, s: str) -> bool:

        binary_str = ""
        
        for char in s:
            print(char)
            ascii_char = ord(char)
            print(ascii_char)

            ascii_bin = format(ascii_char, "08b")
            print(ascii_bin)

            binary_str += str(ascii_bin)
            print(binary_str)

        if binary_str == binary_str[::-1]:
            return True
        else:
            return False

            
            


        
            