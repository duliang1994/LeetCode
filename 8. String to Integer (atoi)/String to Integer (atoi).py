class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        
        ls = list(str.strip())
        if len(ls) == 0: return 0
        sign = -1 if ls[0] == '-' else 1
        if ls[0] in ['+', '-']: del ls[0]
        ans, i = 0, 0
        while i < len(ls) and ls[i].isdigit():
            ans = ans * 10 + ord(ls[i]) - ord('0')
            i += 1
        if sign * ans > 2**31 -1:
            return 2**31 - 1
        elif sign * ans < -2**31:
            return -2**31
        else: return sign * ans
