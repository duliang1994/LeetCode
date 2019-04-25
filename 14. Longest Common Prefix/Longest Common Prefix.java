class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";
       
        for(int j = 0; j < strs[0].length(); j++){
            
            for(int i = 1; i < strs.length; i++){
                if(j >= strs[i].length() || strs[i].charAt(j) != strs[0].charAt(j)){
                    return strs[0].substring(0, j);
                }
            }
            
        }
        return strs[0];
    }
}
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs: return ''
        strs.sort()
        n = min(len(strs[0]), len(strs[-1]))
        i = 0
        
        while i < n and strs[0][i] == strs[-1][i]:
            i += 1
            
        return strs[0][:i]
