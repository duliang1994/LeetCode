class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4 ) return res;
        
        for(int i = 0; i < nums.size() - 3; i++){
            
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int lo = j + 1;
                int hi = nums.size() - 1;
                int temp = target - nums[i] - nums[j];
                while(lo < hi){
                    if(nums[lo] + nums[hi] == temp){
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++;
                        hi--;
                    
                    } else if(nums[lo] + nums[hi] < temp){
                    //while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        lo++;
                    } else {
                    //while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        hi--;
                    }
                }
            }
            
            
            
        }
        return res;
    }
};
