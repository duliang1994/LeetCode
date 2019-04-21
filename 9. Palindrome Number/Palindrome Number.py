class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0: return False;
        div = 1
        while x / div >= 10: div *= 10;
        while x > 0:
            left = x / div
            right = x % 10
            if left != right: return False
            x = (x % div) / 10
            div /= 100
        
        return True
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x != 0 and x % 10 == 0): return False
        reverse = 0
        
        while x > reverse:
            
            reverse = reverse * 10 + x % 10
            x /= 10
        
        return (x == reverse) or (x == reverse / 10)
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x != 0 and x % 10 == 0): return False
        
        
        return x == self.reverse(x)
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        
        
        factor = -1 if x < 0 else 1
        
        if factor == 1:
            reverseX = int(str(x)[::-1])
        else:
            reverseX = int(str(x)[1:][::-1])
            
        
        return 0 if reverseX > (pow(2, 31) - 1) else factor * reverseX
