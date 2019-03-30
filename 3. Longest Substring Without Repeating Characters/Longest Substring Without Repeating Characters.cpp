
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> mapping;
        int maxAns = 0;
        int i, j;
        for(i = 0; i < s.size(); i++){
            mapping.erase(mapping.begin(), mapping.end());
            mapping[s[i]]++;
            for(j = i + 1; j < s.size(); j++){
                mapping[s[j]]++;
                if(mapping[s[j]] == 2){
                    break;
                }
                
            }
            if((j - i) > maxAns){
                maxAns = (j - i);
            }
            
        }
        
           
        return maxAns;
    }
        
    
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //记录每个字符最后出现的位置
        unordered_map<char, int> mapping;
        //滑动窗口左边位置 它总在滑动窗口最左边字符的前一位，以便计算窗口长度，初始化为-1
        int left = -1;
        int maxAns = 0;
        for(int i = 0; i < s.size(); i++){
            
            //判断当前字符是否出现过 即mapping.count(s[i])是否为0，是0表示未出现，1表示出现过
            //如果该字符出现过且在滑动窗口中mapping[s[i]] > left
            //删除该字符，即将left赋值为出现的字符的位置
            if(mapping.count(s[i]) && mapping[s[i]] > left){
                left = mapping[s[i]];
            }
            mapping[s[i]] = i;//储存字符的位置无论是否出现过
            //更新最大长度
            maxAns = max(maxAns, i - left);
            
        }
        return maxAns;
        
    }
        
    
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> mapping(256, -1);
        //滑动窗口左边位置 它总在滑动窗口最左边字符的前一位，以便计算窗口长度，初始化为-1
        int left = -1;
        int maxAns = 0;
        for(int i = 0; i < s.size(); i++){
            
            
            //如果该字符出现过且在滑动窗口中mapping[s[i]] > left
            //删除该字符，即将left赋值为出现的字符的位置
            if(mapping[s[i]] > left){
                left = mapping[s[i]];
            }
            mapping[s[i]] = i;//储存字符的位置无论是否出现过
            //更新最大长度
            maxAns = max(maxAns, i - left);
            
        }
        return maxAns;
        
    }
        
    
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> mapping;
        
        int left = 0;
        int maxAns = 0;
        int i = 0;
        while(i < s.size()){
            
            if(!mapping.count(s[i])){
                
                mapping.insert(s[i++]);
                maxAns = max(maxAns, (int)mapping.size());
            } else {
                mapping.erase(s[left++]);
            }
            
            
            
        }
        return maxAns;
        
    }
        
    
};
