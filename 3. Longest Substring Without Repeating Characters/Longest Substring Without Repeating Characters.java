class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> mapping = new HashMap<Character, Integer>();
        int maxAns = 0;
        int i, j;
        for(i = 0; i < s.length(); i++){
            mapping.clear();
            mapping.put(s.charAt(i), 1);
            for(j = i + 1; j < s.length(); j++){
                if(mapping.containsKey(s.charAt(j))){
                    mapping.put(s.charAt(j), mapping.get(s.charAt(j)) + 1);
                } else {
                    mapping.put(s.charAt(j), 1);
                }
                
                if(mapping.get(s.charAt(j)) == 2){
                    break;
                }
                
            }
            if((j - i) > maxAns){
                maxAns = (j - i);
            }
            
        }
        
           
        return maxAns;
    }
}
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> mapping = new HashMap<Character, Integer>();

        
          
        //滑动窗口左边位置 它总在滑动窗口最左边字符的前一位，以便计算窗口长度，初始化为-1
        int left = -1;
        int maxAns = 0;
        for(int i = 0; i < s.length(); i++){
            
            if(mapping.containsKey(s.charAt(i)) && mapping.get(s.charAt(i)) > left){
                left = mapping.get(s.charAt(i));
            }
            mapping.put(s.charAt(i), i);//储存字符的位置无论是否出现过
            //更新最大长度
            maxAns = Math.max(maxAns, i - left);
            
        }
        return maxAns;
    }
}
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] mapping = new int[256];
        
        Arrays.fill(mapping, -1);
        
          
        //滑动窗口左边位置 它总在滑动窗口最左边字符的前一位，以便计算窗口长度，初始化为-1
        int left = -1;
        int maxAns = 0;
        for(int i = 0; i < s.length(); i++){
            
            if(mapping[s.charAt(i)] > left){
                left = mapping[s.charAt(i)];
            }
            mapping[s.charAt(i)] = i;//储存字符的位置无论是否出现过
            //更新最大长度
            maxAns = Math.max(maxAns, i - left);
            
        }
        return maxAns;
    }
}
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> mapping = new HashSet<Character>();
        
        int left = 0;
        int maxAns = 0;
        int i = 0;
        while(i < s.length()){
            
            if(!mapping.contains(s.charAt(i))){
                
                mapping.add(s.charAt(i++));
                maxAns = Math.max(maxAns, mapping.size());
            } else {
                mapping.remove(s.charAt(left++));
            }
            
            
            
        }
        return maxAns;
        
    }
}
