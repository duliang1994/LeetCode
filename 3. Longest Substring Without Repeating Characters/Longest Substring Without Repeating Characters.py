class Solution(object):
    def lengthOfLongestSubstring(self, s):
        mapping = {}
        maxAns = 0
        for i in range(len(s)):
            mapping.clear()
            
            mapping[s[i]] = 1
            
            j = i + 1
            while j < len(s):
                
                if s[j] in mapping:
                    mapping[s[j]] = mapping[s[j]] + 1
                else:
                    mapping[s[j]] = 1
                
                if mapping[s[j]] == 2:
                    break;
                j = j + 1
            if (j - i) > maxAns:
                maxAns = (j - i)
            
           
        return maxAns
        
 class Solution(object):
    def lengthOfLongestSubstring(self, s):
        mapping = {}
        
        left = -1
        maxAns = 0
        for i in range(len(s)):
            
            if s[i] in mapping and mapping[s[i]] > left:
                left = mapping[s[i]]
            
            mapping[s[i]] = i
           
            maxAns = max(maxAns, i - left)
            
        
        return maxAns
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        mapping = [-1] * 256
        
        left = -1
        maxAns = 0
        for i in range(len(s)):
            
            if mapping[(ord)s[i]] > left:
                left = mapping[(ord)s[i]]
            
            mapping[(ord)s[i]] = i
           
            maxAns = max(maxAns, i - left)
            
        
        return maxAns
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        mapping = set()
        
        left = 0
        maxAns = 0
        i = 0
        while i < len(s):
            
            if s[i] not in mapping:
                
                mapping.add(s[i])
                i = i + 1
                maxAns = max(maxAns, len(mapping))
            else:
                mapping.remove(s[left])
                left = left + 1
            
            
            
        
        return maxAns
 
