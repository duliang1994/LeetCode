class Solution {
public:
    int lo = 0;
    int maxLen = 0;
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        for(int i = 0; i < s.size() - 1; i++){
            //假设回文字符串为奇数
            findPalindromic(s, i, i);
            //假设回文字符串为偶数
            findPalindromic(s, i, i + 1);
        }
        return s.substr(lo, maxLen);
    }
    void findPalindromic(string s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        if((right - left - 1) > maxLen){
            maxLen = (right - left - 1);
            lo = left + 1;
        }
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int n = s.size();
        int lo = 0;
        int maxLen = 0;
        for(int i = 0; i < n;){
            if((n - i) <= (maxLen / 2)) break;
            int left = i, right = i;
            while(right < (n - 1) && s[right] == s[right + 1]) right++;
            i = right + 1;
            while(left > 0 && right < (n - 1) && s[left - 1] == s[right + 1]){
                left--;
                right++;
            }
            if(maxLen < (right - left + 1)){
                maxLen = (right - left + 1);
                lo = left;
            }
        }
        return s.substr(lo, maxLen);
    }
   
};
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int n = s.size();
        int lo = 0;
        int maxLen = 1;
        int dp[n][n] = {0};
        
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            
            for(int j = 0; j < i; j++){
                dp[j][i] = (s[i] == s[j]) && (((i - j) < 2) || dp[j + 1][i - 1]);
                if(dp[j][i] && maxLen < (i - j + 1)){
                    lo = j;
                    maxLen = (i - j + 1);
                }
            }
            
        }
        return s.substr(lo, maxLen);
    }
   
};
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(int i = 0; i < s.size(); i++){
            t += s[i];
            t += "#";
        }
        vector<int> p(t.size(), 0);
       // int p[t.size()] = {0};
        int id = 0, mx = 0, resCenter = 0, resLen = 0;
        for(int i = 1; i < t.size(); i++){
            p[i] = (mx > i) ? min(p[2 * id - i], mx - i) : 1;
            while(t[i + p[i]] == t[i - p[i]]) p[i]++;
            if(i + p[i] > mx){
                id = i;
                mx = (i + p[i]);
            }
            if(p[i] > resLen){
                resCenter = i;
                resLen = p[i];
            }
        }
        
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
   
};
