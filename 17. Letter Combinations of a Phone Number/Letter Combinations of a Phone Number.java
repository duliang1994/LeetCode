class Solution {
    public String[] keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public List<String> letterCombinations(String digits) {
        
        List<String> res = new ArrayList<>();
        if(digits == null || digits.length() == 0) return res;
        DFS(digits, 0, "", res);
        return res;
    }
     
    
    
    public void DFS(String digits, int cur, String path, List<String> res){
        if(cur == digits.length()){
            res.add(path);
            return;
        }
        String key = keyboard[digits.charAt(cur) - '0'];
        for(int i = 0; i < key.length(); i++){
            DFS(digits, cur + 1, path + key.charAt(i), res);
        }
    }
}

class Solution {
    
    public List<String> letterCombinations(String digits) {
        String[] keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> res = new ArrayList<>();
        if(digits == null || digits.length() == 0) return res;
        
        res.add("");
       
        for(int i = 0; i < digits.length(); i++){
            List<String> t = new ArrayList<>();
            String key = keyboard[digits.charAt(i) - '0'];
            for(int j = 0; j < key.length(); j++){
                for(String s : res){
                    t.add(s + key.charAt(j));
                }
            }
            res = t;
            
        }
       
        return res;
    }
