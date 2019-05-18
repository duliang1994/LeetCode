class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        DFS(0, 0, "", n, res);
        return res;
    }
    void DFS(int left, int right, string path, int n, vector<string>& res){
        if(right > left || left > n || right > n) return;
        
        if(left == n && right == n){
            
            res.push_back(path);
            return;   
        }
        DFS(left + 1, right, path + '(', n, res);
        DFS(left, right + 1, path + ')', n, res);
    }
    
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector< vector<string> > dp(n + 1, vector<string>());
        //vector<string> dp[n + 1];
        dp[0].push_back("");
        for(int i = 1; i <= n; i++){
            for(int k = 0; k < i;k++){
                for(string s2: dp[i-1-k]){
                    for(string s1: dp[k]){
                        dp[i].push_back("(" + s1 + ")" + s2);
                    }
                }
            }
        }
        return dp[n];
    }
   
    
};
