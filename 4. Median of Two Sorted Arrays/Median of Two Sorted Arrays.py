class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        ans = [0] * (n + m)
    
        i, j , index = 0, 0, 0
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                ans[index] = nums1[i]
                i = i + 1
                index = index + 1
            else:
                ans[index] = nums2[j]
                j = j + 1
                index = index + 1
            
        
        while i < m: 
            ans[index] = nums1[i]
            i = i + 1
            index = index + 1
        while j < n:
            ans[index] = nums2[j]
            j = j + 1
            index = index + 1
       # print ans
        if index % 2:
            median = ans[index / 2]
        else:
            median = (ans[index / 2] + ans[index / 2 - 1]) / 2.0
        
        return median;
class Solution(object):
    
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        def findKth(A, i, B, j, k):
        
            if i >= len(A): return B[j + k - 1]

            if j >= len(B): return A[i + k - 1]
            if k == 1: return min(A[i], B[j])

            midA = A[i + k / 2 - 1] if (i + k / 2 - 1) < len(A) else sys.maxsize
            midB = B[j + k / 2 - 1] if (j + k / 2 - 1) < len(B) else sys.maxsize

            if midA < midB:
                return findKth(A, i + k / 2, B, j, k - k / 2)
            else:
                return findKth(A, i, B, j + k / 2, k - k / 2)
        m = len(nums1)
        n = len(nums2)
        
        total = m + n
        
        if total % 2 == 1:
            return findKth(nums1, 0, nums2, 0, total // 2 + 1)
        else:
            return (findKth(nums1, 0, nums2, 0, total // 2) + findKth(nums1, 0, nums2, 0, total // 2 + 1)) / 2.0
            
class Solution(object):
    
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        m , n = len(nums1), len(nums2)
        if m > n: 
            nums1, m, nums2, n = nums2, n, nums1, m
        lo = 0
        hi = m
        while lo <= hi:
            cut1 = (lo + hi) >> 1
           # print cut1
            cut2 = ((m + n) >> 1) - cut1
           # print cut2
            l1 = -sys.maxsize - 1 if (cut1 == 0) else (nums1[cut1 - 1])
            l2 = -sys.maxsize - 1 if (cut2 == 0) else (nums2[cut2 - 1])
            r1 = sys.maxsize if (cut1 == m) else (nums1[cut1])
            r2 = sys.maxsize if (cut2 == n) else (nums2[cut2])
            if l1 > r2:
                hi = cut1 - 1
            elif l2 > r1:
                lo = cut1 + 1
            else:
                if (m + n) % 2:
                    return min(r1, r2)
                else:
                    return (max(l1, l2) + min(r1, r2)) / 2.0
                
            
        
        return 0.0;
