import unittest

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        return 2

class TestSolution(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_upper(self):
        res = self.solution.findMedianSortedArrays([1, 2], [3]) 
        self.assertEqual(res, 2)

if __name__ == '__main__':
    unittest.main()
