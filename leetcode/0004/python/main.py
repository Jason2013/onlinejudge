import unittest

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        assert nums1 or nums2

        if not nums1:
            return self.findMedianSortedArray(nums2)

        if not nums2:
            return self.findMedianSortedArray(nums1)

        n = len(nums1)
        m = len(nums2)

        half = (n + m)//2

        low = 0
        high = min(n, half)
        while low <= high:
            x = (low + high)//2
            y = half - x # number of nums2
            if y > m:
                low = x + 1
                continue

            if x == n:
                if nums1[x-1] > nums2[y]:
                    high = x - 1
                else:
                    return self.findResult(nums1, n, x, nums2, m, y)
            elif x == 0:
                if nums2[y-1] > nums1[x]:
                    low = x + 1
                else:
                    return self.findResult(nums1, n, x, nums2, m, y)
            else:
                if y == m:
                    if nums2[y-1] > nums1[x]:
                        low = x + 1
                    else:
                        return self.findResult(nums1, n, x, nums2, m, y)
                elif y == 0:
                    if nums1[x-1] > nums2[y]:
                        high = x - 1
                    else:
                        return self.findResult(nums1, n, x, nums2, m, y)
                else:
                    if nums1[x-1] > nums2[y]:
                        high = x - 1
                    else:
                        if nums2[y-1] > nums1[x]:
                            low = x + 1
                        else:
                            return self.findResult(nums1, n, x, nums2, m, y)

    def findResult(self, nums1, n, x, nums2, m, y):
        odd = (n + m) % 2 == 1
        if odd:
            if x == n:
                return nums2[y]
            if y == m:
                return nums1[x]
            return min(nums1[x], nums2[y])
        else:
            if x == 0:
                t1 = nums2[y-1]
            elif y == 0:
                t1 = nums1[x-1]
            else:
                t1 = max(nums1[x-1], nums2[y-1])
            if x == n:
                t2 = nums2[y]
            elif y == m:
                t2 = nums1[x]
            else:
                t2 = min(nums1[x], nums2[y])
            return (t1+t2)/2

    def findMedianSortedArray(self, nums):
        length = len(nums)
        if length % 2 == 1: # Odd
            return nums[length//2]
        else: # Even
            right = length//2
            left = right - 1
            return (nums[left] + nums[right])/2

class TestSolution(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_findMedianSortedArray1(self):
        nums = [1]
        res = self.solution.findMedianSortedArray(nums)
        self.assertEqual(res, 1)

    def test_findMedianSortedArray2(self):
        nums = [1, 2]
        res = self.solution.findMedianSortedArray(nums)
        self.assertEqual(res, 1.5)

    def test_case1(self):
        nums1 = [1, 3]
        nums2 = [2]
        res = self.solution.findMedianSortedArrays(nums1, nums2) 
        self.assertEqual(res, 2)

    def test_case2(self):
        nums1 = [1, 2]
        nums2 = [3, 4]
        res = self.solution.findMedianSortedArrays(nums1, nums2) 
        self.assertEqual(res, 2.5)

    def test_case3(self):
        nums1 = [0, 0]
        nums2 = [0, 0]
        res = self.solution.findMedianSortedArrays(nums1, nums2) 
        self.assertEqual(res, 0)

    def test_case4(self):
        nums1 = []
        nums2 = [1]
        res = self.solution.findMedianSortedArrays(nums1, nums2) 
        self.assertEqual(res, 1)

    def test_case5(self):
        nums1 = [2]
        nums2 = []
        res = self.solution.findMedianSortedArrays(nums1, nums2) 
        self.assertEqual(res, 2)

if __name__ == '__main__':
    unittest.main()
