class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxArea = 0
        length = len(height)
        
        for i in range(length):
            for j in range(i + 1, length):
                minNum = min(height[i], height[j])
                area = (j - i) * minNum
                if area > maxArea:
                    maxArea = area
                
            
        
        return maxArea
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxArea = 0
        l = 0
        r = len(height) - 1
        while l < r:
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]: l += 1
            else: r -= 1
                
        
        
        return maxArea     
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxArea = 0
        l = 0
        r = len(height) - 1;
        while l < r:
            minHeight = min(height[l], height[r])
            maxArea = max(maxArea,minHeight * (r - l))
            while l < r and height[l] <= minHeight: l += 1
            while l < r and height[r] <= minHeight: r -= 1
            
                
        
        
        return maxArea
