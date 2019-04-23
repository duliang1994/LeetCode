class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int length = height.size();
        //int i = 0;
        //int j = 1;
        for(int i = 0; i < length; i++){
            for(int j = i + 1; j < length; j++){
                int minNum = min(height[i], height[j]);
                int area = (j - i) * minNum;
                if(area > maxArea){
                    maxArea = area;
                }
            }
        }
        return maxArea;
        
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r]) l++;
            else r--;
                
        }
        
        return maxArea;
        
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            int minHeight = min(height[l], height[r]);
            maxArea = max(maxArea,minHeight * (r - l));
            while(l < r && height[l] <= minHeight) l++;
            while(l < r && height[r] <= minHeight) r--;
            
                
        }
        
        return maxArea;
        
    }
};
