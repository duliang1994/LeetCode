class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int max = INT_MIN;
        int ans;
        for(int i = 0; i < nums.size(); i++){
             ans = nums[i];
            if(ans > max){
                max = ans;
            }
            for(int j = i + 1; j < nums.size(); j++){
                ans += nums[j];
                if(ans > max){
                    max = ans;
                }
            }
        }
        return max;
        
    }
};
