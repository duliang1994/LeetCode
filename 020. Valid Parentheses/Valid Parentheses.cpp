class Solution {
public:
    bool isValid(string s) {
        
        stack<char> sk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                sk.push(s[i]);
            } else {
                if(sk.empty()) return false;
    
                char temp = sk.top();
                if(s[i] == ')' && temp != '(') return false;
                if(s[i] == ']' && temp != '[') return false;
                if(s[i] == '}' && temp != '{') return false;
                    
                sk.pop();
                
                
            }
           
        }
       return sk.empty();
    }
};
