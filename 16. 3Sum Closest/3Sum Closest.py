class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res = 0
        min_gap = sys.maxsize
        nums.sort()
       
        
        for i in range(len(nums) - 2):
            
            if i > 0 and nums[i] == nums[i - 1]: continue
            lo = i + 1
            hi = len(nums) - 1
            
            while lo < hi:
                sum = (nums[i] + nums[lo] + nums[hi])
                if sum == target: return sum
                if abs(sum - target) < min_gap:
                    res = sum
                    min_gap = abs(sum - target)
                
                
                    
                if sum < target:
                    #while lo < hi and nums[lo] == nums[lo + 1]: lo += 1
                    lo += 1
                else:
                    #while lo < hi and nums[hi] == nums[hi - 1]: hi -= 1
                    hi -= 1
               
            
        
        return res;
