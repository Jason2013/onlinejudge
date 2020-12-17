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

        if n < m:
            nums1, nums2 = nums2, nums1
            n, m = m, n

        if n == 1 and m == 1:
            return (nums1[0] + nums2[0])/2

        length = n + m
        if length % 2 == 1:
            half = int(length/2)
            odd = True
        else:
            half = int(length/2) - 1
            odd = False

        x = int(half/2)
        y = half - x - 1
        while x >= 0 and x <= half:
            assert y >= 0 and y < m
            if nums1[x] <= nums2[y+1]:
                if y == m - 1 or nums2[y] <= nums1[x+1]:
                    if odd:
                        return nums1[x]
                    else:
                        return (max(nums1[x], nums2[y]) + min(nums1[x+1], nums2[y+1]))/2
                else:
                    x = int(((x+1) + half)/2)
                    y = half - x - 1
            else:
                x = int((x-1)/2)
                y = half - x - 1

        assert False
        # nums = sorted(nums1 + nums2)
        # return findMedianSortedArray(nums)

    def findMedianSortedArray(self, nums):
        length = len(nums)
        if length % 2 == 1: # Odd
            return nums[int((length - 1)/2)]
        else: # Even
            right = int(length/2)
            left = right - 1
            return (nums[left] + nums[right])/2

class TestSolution(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

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
