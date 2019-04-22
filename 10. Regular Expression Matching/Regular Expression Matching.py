class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p:
            return not s
        first_match = bool(s) and p[0] in {s[0], '.'}
        if len(p) > 1 and p[1] == '*':
            return (self.isMatch(s, p[2:])) or first_match and self.isMatch(s[1:], p)
        else:
            return first_match and self.isMatch(s[1:], p[1:])
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m = len(s)
        n = len(p)
        dp = [[False] * (n + 1) for i in range(m + 1)]
        #print(dp[0][1])
       # print(dp)
        dp[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                print(i, j)
                if j > 1 and p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or (i > 0 and p[j - 2] in{'.', s[i - 1]}) and dp[i -1][j]
                else:
                    dp[i][j] = (i > 0 and p[j - 1] in{'.', s[i - 1]} and dp[i -1][j - 1])
                
            
        
        return dp[m][n]
