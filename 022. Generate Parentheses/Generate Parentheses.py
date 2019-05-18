class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        
        self.DFS(0, 0, "", n, res)
        return res
    def DFS(self, left, right, path, n, res):
        if right > left or left > n or right > n: return;
        
        if left == n and right == n:
            
            res.append(path);
            return;   
        
        self.DFS(left + 1, right, path + '(', n, res)
        self.DFS(left, right + 1, path + ')', n, res)
    
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        dp = [[] for i in range(n + 1)]
        dp[0].append("")
        for i in range(1, n + 1):
            for k in range(i):
                dp[i] += ["(" + x + ")" + y for x in dp[k] for y in dp[i - 1 - k]]      
        
        
        return dp[n]
