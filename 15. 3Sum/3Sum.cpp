class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return res;
        
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1;
            int hi = nums.size() - 1;
            int target = 0 - nums[i];
            while(lo < hi){
                if(nums[lo] + nums[hi] == target){
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++;
                    hi--;
                    
                } else if(nums[lo] + nums[hi] < target){
                   // while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    lo++;
                } else {
                    //while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    hi--;
                }
            }
            
            
        }
        return res;
    }
};
