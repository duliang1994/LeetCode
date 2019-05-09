class Solution {
    public boolean isValid(String s) {
        Stack<Character> sk = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{'){
                sk.push(s.charAt(i));
            } else {
                if(sk.empty()) return false;
    
                char temp = sk.peek();
                if(s.charAt(i) == ')' && temp != '(') return false;
                if(s.charAt(i) == ']' && temp != '[') return false;
                if(s.charAt(i) == '}' && temp != '{') return false;
                    
                sk.pop();
                
                
            }
           
        }
       return sk.empty();
    }
}
