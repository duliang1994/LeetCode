class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());
       
        
        for(int i = 0; i < nums.size() - 2; i++){
            
           if(i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1;
            int hi = nums.size() - 1;
            
            while(lo < hi){
                int sum = (nums[i] + nums[lo] + nums[hi]);
                if(sum == target) return sum;
                if(abs(sum - target) < min_gap){
                    res = sum;
                    min_gap = abs(sum - target);
                }
                
                    
                if(sum < target){
                   while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    lo++;
                } else {
                    while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    hi--;
                }
            }
            
            
        }
        return res;
    }
};
   
