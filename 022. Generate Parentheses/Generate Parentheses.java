class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        
        DFS(0, 0, "", n, res);
        return res;
    }
    public void DFS(int left, int right, String path, int n, List<String> res){
        if(right > left || left > n || right > n) return;
        
        if(left == n && right == n){
            
            res.add(path);
            return;   
        }
        DFS(left + 1, right, path + '(', n, res);
        DFS(left, right + 1, path + ')', n, res);
    }
}
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> dp[] = new List[n + 1];
        dp[0] = Collections.singletonList("");
        //dp[0] = Arrays.asList("");
        for(int i = 1; i <= n; i++){
            List<String> temp = new ArrayList<>();
            for(int k = 0; k < i;k++){
                for(String s1: dp[k]){
                    for(String s2: dp[i-1-k]){
                        temp.add("(" + s1 + ")" + s2);
                    }
                }
            }
            dp[i] = temp;
        }
        return dp[n];
        
    }
    
}
class Solution {
    public List<String> generateParenthesis(int n) {
        List<List<String>>dp = new ArrayList<>();
        //dp.add(Collections.singletonList(""));
        dp.add(Arrays.asList(""));
        for(int i = 1; i <= n; i++){
            List<String> temp = new ArrayList<>();
            for(int k = 0; k < i;k++){
                for(String s1: dp.get(k)){
                    for(String s2: dp.get(i-1-k)){
                        temp.add("(" + s1 + ")" + s2);
                    }
                }
            }
            dp.add(temp);
        }
        return dp.get(dp.size() - 1);
        
    }
    
}
