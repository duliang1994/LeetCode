class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         for(vector<int> :: iterator it = nums.begin(); it != nums.end(); ){
            if(*it == val){
                nums.erase(it);
            } else {
                it++;
            }
        }
        return nums.size();
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int index = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] != val){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
