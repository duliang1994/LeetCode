class Solution(object):
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        if not digits: return res
        keyboard = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.DFS(digits, keyboard, 0, "", res)
        return res
    def DFS(self, digits, keyboard, cur, path, res):
        if cur == len(digits):
            res.append(path)
            return;
        
        key = keyboard[ord(digits[cur]) - ord('0')]
        for c in key:
            self.DFS(digits, keyboard, cur + 1, path + c, res)
class Solution(object):
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        if not digits: return res
        keyboard = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
        res.append("")
        for digit in digits:
            t = []
            key = keyboard[digit]
            
            for char in key:
                
                for str in res:
                    
                    t.append(str + char)
            res = t
        return res
