class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        if(x < 0) return false;
        //if(x == 0) return true;
        long long reverse = 0;
        while(temp){
            reverse = reverse * 10 + (temp % 10);
            temp /= 10;
        }
        
        bool flag;
        
        flag = (reverse == x ) ? true : false;
        return flag;
        
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
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
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        int reverse = 0;
        
        while(x > reverse){
            
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (x == reverse) || (x == reverse / 10);
        
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        
        return x == reverse(x);
        
    }
    int reverse(int x) {
        
        int ans = 0;
        //cout << (INT_MAX % 10) << (INT_MIN % 10);
        while(x != 0){
            int pop = x % 10;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > (INT_MAX % 10))) return 0;
            
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < (INT_MIN % 10))) return 0;
            ans = ans * 10 + pop;
            
            x /= 10;
            
        }
        return ans;
    }
};
