class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        dict = {"]":"[", "}":"{", ")":"("}
        for i in s:
            if i in dict.values():
                stack.append(i)
            else:
                if not stack or dict[i] != stack[-1]: return False
                stack.pop()
        return not stack
