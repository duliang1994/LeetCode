class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        m = {'I' : 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        for i in range(len(s)):
            if i == 0 or m[s[i]] <= m[s[i - 1]]: res += m[s[i]]
            else: res += (m[s[i]] - 2 * m[s[i - 1]])
        
        return res
