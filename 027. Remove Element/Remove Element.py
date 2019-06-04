class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        n = len(nums)
        index = 0
        for num in nums:
            if num != val:
                nums[index] = num
                index += 1
            
        
        return index
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        while val in nums:
            nums.pop(nums.index(val))
           # nums.remove(val)
            
        
        return len(nums)
