class Solution {
    private int lo = 0;
    private int maxLen = 0;
    public String longestPalindrome(String s) {
        if(s.length() < 2) return s;
        for(int i = 0; i < s.length() - 1; i++){
            //假设回文字符串为奇数
            findPalindromic(s, i, i);
            //假设回文字符串为偶数
            findPalindromic(s, i, i + 1);
        }
        return s.substring(lo, lo + maxLen);
    }
    private void findPalindromic(String s, int left, int right){
        while(left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        if((right - left - 1) > maxLen){
            maxLen = (right - left - 1);
            lo = left + 1;
        }
    }
    
}

class Solution {
    
    public String longestPalindrome(String s) {
        if(s.length() < 2) return s;
        int n = s.length();
        int lo = 0;
        int maxLen = 0;
        for(int i = 0; i < n;){
            if((n - i) <= (maxLen / 2)) break;
            int left = i, right = i;
            while(right < (n - 1) && s.charAt(right) == s.charAt(right + 1)) right++;
            i = right + 1;
            while(left > 0 && right < (n - 1) && s.charAt(left - 1) == s.charAt(right + 1)){
                left--;
                right++;
            }
            if(maxLen < (right - left + 1)){
                maxLen = (right - left + 1);
                lo = left;
            }
        }
        return s.substring(lo, lo + maxLen);
    }
    
    
}

class Solution {
    
    public String longestPalindrome(String s) {
        if(s.length() < 2) return s;
        int n = s.length();
        int lo = 0;
        int maxLen = 1;
        int[][] dp = new int[n][n];
        
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            
            for(int j = 0; j < i; j++){
                if((s.charAt(i) == s.charAt(j)) && (((i - j) < 2) || dp[j + 1][i - 1] == 1)){
                    dp[j][i] = 1;
                }
                
                if(dp[j][i] == 1 && maxLen < (i - j + 1)){
                    lo = j;
                    maxLen = (i - j + 1);
                }
            }
            
        }
        return s.substring(lo, lo + maxLen);
    }
    
    
}
class Solution {
    
    public String longestPalindrome(String s) {
        StringBuilder t = new StringBuilder("$#");
        for(int i = 0; i < s.length(); i++){
            t.append(s.charAt(i));
            t.append("#");
        }
        t.append("\0");
        //System.out.println(t);
        
       // int p[t.size()] = {0};
        int[] p = new int[t.length()];
        int id = 0, mx = 0, resCenter = 0, resLen = 0;
        for(int i = 1; i < t.length() - 1; i++){
            p[i] = (mx > i) ? Math.min(p[2 * id - i], mx - i) : 1;
            while(t.charAt(i + p[i]) == t.charAt(i - p[i])) p[i]++;
            //System.out.println("i是"+i+"p[i]是"+p[i]);
            if(i + p[i] > mx){
                id = i;
                mx = (i + p[i]);
            }
            if(p[i] > resLen){
                resCenter = i;
                resLen = p[i];
            }
        }
        
        return s.substring((resCenter - resLen) / 2, (resCenter - resLen) / 2 + resLen - 1);
    }
    
    
}
