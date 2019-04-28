class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        if len(nums) < 3 or nums[0] > 0 or nums[-1] < 0: return res
        
        for i in range(len(nums) - 2):
            if nums[i] > 0: break
            if i > 0 and nums[i] == nums[i - 1]: continue
            lo, hi = i + 1, len(nums) - 1
            
            target = 0 - nums[i]
            while lo < hi:
                if nums[lo] + nums[hi] == target:
                    res.append((nums[i], nums[lo], nums[hi]))
                    while lo < hi and nums[lo] == nums[lo + 1]: lo += 1
                    while lo < hi and nums[hi] == nums[hi - 1]: hi -= 1
                    lo += 1
                    hi -= 1
                    
                elif nums[lo] + nums[hi] < target:
                    #while lo < hi and nums[lo] == nums[lo + 1]: lo += 1
                    lo += 1
                else: 
                    #while lo < hi and nums[hi] == nums[hi - 1]: hi -= 1
                    hi -= 1
