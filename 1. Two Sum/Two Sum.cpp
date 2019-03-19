//暴力二重循环
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.clear();
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
       return ans;
    }
};
//map法 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(target - nums[i]) != m.end()){
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
            
        }
        return ans;
        
    }
};
