class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        if len(nums) < 4 : return res
        
        for i in range(len(nums) - 3):
            
            if i > 0 and nums[i] == nums[i - 1]: continue
            for j in range(i + 1, len(nums) - 2):
                if j > i + 1 and nums[j] == nums[j - 1]: continue
                lo, hi = j + 1, len(nums) - 1
            
                temp = target - nums[i] - nums[j]
                while lo < hi:
                    if nums[lo] + nums[hi] == temp:
                        res.append((nums[i],nums[j], nums[lo], nums[hi]))
                        while lo < hi and nums[lo] == nums[lo + 1]: lo += 1
                        while lo < hi and nums[hi] == nums[hi - 1]: hi -= 1
                        lo += 1
                        hi -= 1
                    
                    elif nums[lo] + nums[hi] < temp:
                    
                        lo += 1
                    else: 
                    
                        hi -= 1
           
        return res;
