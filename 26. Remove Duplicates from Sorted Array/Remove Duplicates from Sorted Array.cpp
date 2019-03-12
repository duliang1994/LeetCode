class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        int j = 1;
        
        while(i < nums.size() && j < nums.size() ){
            while(nums[j] == nums[i]) {
                j++;
                if(j >= nums.size()) {
                    return i + 1;
                }
            }
            nums[i + 1] = nums[j];
            i++;
            
        }
        return i + 1;
        
    }
};
