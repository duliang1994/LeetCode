class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        ans = 0
        num = abs(x)
        
        factor = 1 if x > 0 else -1
        
        while num != 0:
            
           
            ans = ans * 10 + (num % 10)
            
            
            num /= 10
            
        
        return 0 if ans > (pow(2, 31) - 1) else factor * ans
class Solution(object):
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
