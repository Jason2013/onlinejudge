import unittest

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        nums = sorted(nums1 + nums2)
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
