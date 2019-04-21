class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        int div = 1;
        while(x / div >= 10) div *= 10;
        while(x > 0){
            int left = x / div;
            int right = x % 10;
            if(left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
}
class Solution {
    public boolean isPalindrome(int x) {
       if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        int reverse = 0;
        
        while(x > reverse){
            
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (x == reverse) || (x == reverse / 10);
    }
}
class Solution {
    public boolean isPalindrome(int x) {
       if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        
        
        return x == reverse(x);
    }
    public int reverse(int x) {
        int ans = 0;
        
        while(x != 0){
            
            int remainder = x % 10;
            int newAns = ans * 10 + remainder;
            if((newAns - remainder) / 10 != ans) return 0;
            ans = newAns;
            
            x /= 10;
            
        }
        return ans;
    }
}
