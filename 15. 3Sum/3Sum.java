class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        if(nums.length < 3 || nums[0] > 0 || nums[nums.length - 1] < 0) return res;
        
        for(int i = 0; i < nums.length - 2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1;
            int hi = nums.length - 1;
            int target = 0 - nums[i];
            while(lo < hi){
                if(nums[lo] + nums[hi] == target){
                    res.add(Arrays.asList(nums[i], nums[lo], nums[hi]));
                    while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++;
                    hi--;
                    
                } else if(nums[lo] + nums[hi] < target){
                    //while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    lo++;
                } else {
                    //while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    hi--;
                }
            }
            
            
        }
        return res;
    }
}
