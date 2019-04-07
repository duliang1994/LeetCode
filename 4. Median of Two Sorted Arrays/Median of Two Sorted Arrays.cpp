class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans[n + m];
        double median;
        int i = 0, j = 0, index = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                ans[index++] = nums1[i++];
            } else {
                ans[index++] = nums2[j++];
            }
        }
        while(i < m) ans[index++] = nums1[i++];
        while(j < n) ans[index++] = nums2[j++];
        if(index % 2){
            median = (double)ans[index / 2];
        } else {
            median = (ans[index / 2] + ans[index / 2 - 1]) / 2.0;
        }
        return median;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        //如果总长度是奇数
        if(total & 0x1){
            return (double)findKth(nums1, 0, nums2, 0, total / 2 + 1);
        } else {
           // cout << findKth(nums1, 0, nums2, 0, total / 2) << endl;
            //cout << findKth(nums1, 0, nums2, 0, total / 2 + 1) << endl;
            
            return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
        }
    }
    //寻找A和B数组中第k小的数
    //i,j分别为指针 指向开始查找的位置
    int findKth(vector<int>& A, int i, vector<int>& B, int j, int k){
        //i超过A数组的边界 说明A中没有要查找的元素 直接返回B中的元素
        if(i >= A.size()) return B[j + k - 1];
        //j超过B数组的边界 说明B中没有要查找的元素 直接返回A中的元素
        if(j >= B.size()) return A[i + k - 1];
        if(k == 1) return min(A[i], B[j]);
        //两个数组同时二分
        //每个数组找到第k/2个元素 如果越界 取最大值INT_MAX
        int midA = ((i + k / 2 - 1) < A.size()) ? A[i + k / 2 - 1] : INT_MAX;
        int midB = ((j + k / 2 - 1) < B.size()) ? B[j + k / 2 - 1] : INT_MAX;
        if(midA < midB){
            return findKth(A, i + k / 2, B, j, k - k / 2);
        } else {
            return findKth(A, i, B, j + k / 2, k - k / 2);
        }
        
    }
       
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int lo = 0;
        int hi = m;
        while(lo <= hi){
            int cut1 = (lo + hi) / 2;
            int cut2 = (m + n) / 2 - cut1;
            int l1 = (cut1 == 0) ? INT_MIN : (nums1[cut1 - 1]);
            int l2 = (cut2 == 0) ? INT_MIN : (nums2[cut2 - 1]);
            int r1 = (cut1 == m) ? INT_MAX : (nums1[cut1]);
            int r2 = (cut2 == n) ? INT_MAX : (nums2[cut2]);
            if(l1 > r2){
                hi = cut1 - 1;
            } else if(l2 > r1) {
                lo = cut1 + 1;
            } else {
                return (m + n) % 2 ? min(r1, r2) : (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        return 0.0;
    }
};
