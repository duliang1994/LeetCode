class Solution(object):
    
    
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        if len(s) < 2: return s
        for i in xrange(len(s)):
            temp = self.findPalindromic(s, i, i)
            if len(temp) > len(res):
                res = temp
            temp = self.findPalindromic(s, i, i + 1)
            if len(temp) > len(res):
                res = temp
        return res
        
    def findPalindromic(self, s, left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
        
            return s[left + 1 : right]
class Solution(object):
    
    
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s) 
        lo, maxLen = 0, 0
        if len(s) < 2: return s
        for i in xrange(len(s)):
            if (n - i) <= (maxLen / 2): break
            left = right = i
            while right < (n - 1) and s[right] == s[right + 1]: right += 1;
            i = right + 1
            while left > 0 and right < (n - 1) and s[left - 1] == s[right + 1]:
                left -= 1
                right += 1
            
            if maxLen < (right - left + 1):
                maxLen = (right - left + 1)
                lo = left
            
        
        return s[lo : lo + maxLen]
class Solution(object):
    
    
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s) 
        lo, maxLen = 0, 1
        if len(s) < 2: return s
        dp = [[0] * n for i in range(n)]
        for i in xrange(len(s)):
            dp[i][i] = 1
            j = 0
            while j < i:
                dp[j][i] = (s[i] == s[j]) and (((i - j) < 2) or dp[j + 1][i - 1])
                if dp[j][i] and maxLen < (i - j + 1):
                    lo = j
                    maxLen = (i - j + 1)
                
                j += 1
             
            
        
        return s[lo : lo + maxLen]
        
class Solution(object):
    
    
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = "$#"
        for i in xrange(len(s)):
            t += s[i]
            t += "#"
        t += "\0"
        p = [0] * len(t)
        id = mx = resCenter = resLen = 0
        for i in range(1, len(t) - 1):
            p[i] = min(p[2 * id - i], mx - i) if (mx > i) else 1
            while t[i + p[i]] == t[i - p[i]]: p[i] += 1
            if i + p[i] > mx:
                id = i
                mx = (i + p[i])
            
            if p[i] > resLen:
                resCenter = i
                resLen = p[i]
            
        return s[(resCenter - resLen) / 2 : (resCenter - resLen) / 2 + resLen - 1]
        
