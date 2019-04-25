class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
       
        for(int j = 0; j < strs[0].size(); j++){
            
            for(int i = 1; i < strs.size(); i++){
                if(j >= strs[i].size() || strs[i][j] != strs[0][j]){
                    return strs[0].substr(0, j);
                }
            }
            
        }
        return strs[0];
        
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
       
        sort(strs.begin(), strs.end());
        int n = min(strs[0].size(), strs.back().size());
        for(int i = 0; i < n; i++){
            if(strs[0][i] != strs.back()[i]) return strs[0].substr(0, i);
        }
        return strs[0];
        
    }
};
