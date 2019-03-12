class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        if(nums.size() == 0 || nums[i] > target ) return 0;
        
        while(i < nums.size() && (nums[i] <= target) ) i++;
        i--;
        if(nums[i] == target) {
            return i;
        } else {
            return i + 1;
        }
    }
};
