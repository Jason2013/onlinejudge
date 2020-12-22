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
            x1 = x-1
            x2 = x
            y1 = y-1
            y2 = y

            if x == n:
                if nums1[x1] > nums2[y2]:
                    high = x - 1
                else:
                    return self.findResult(nums1, n, x1, x2, nums2, m, y1, y2)
            elif x == 0:
                if nums2[y1] > nums1[x2]:
                    low = x + 1
                else:
                    return self.findResult(nums1, n, x1, x2, nums2, m, y1, y2)
            else:
                if y == m:
                    if nums2[y1] > nums1[x2]:
                        low = x + 1
                    else:
                        return self.findResult(nums1, n, x1, x2, nums2, m, y1, y2)
                elif y == 0:
                    if nums1[x1] > nums2[y2]:
                        high = x - 1
                    else:
                        return self.findResult(nums1, n, x1, x2, nums2, m, y1, y2)
                else:
                    if nums1[x1] > nums2[y2]:
                        high = x - 1
                    else:
                        if nums2[y1] > nums1[x2]:
                            low = x + 1
                        else:
                            return self.findResult(nums1, n, x1, x2, nums2, m, y1, y2)

    def findResult(self, nums1, n, x1, x2, nums2, m, y1, y2):
        odd = (n + m) % 2 == 1
        if odd:
            if x2 not in range(n):
                return nums2[y2]
            if y2 not in range(m):
                return nums1[x2]
            return min(nums1[x2], nums2[y2])
        else:
            if x1 not in range(n):
                t1 = nums2[y1]
            elif y1 not in range(m):
                t1 = nums1[x1]
            else:
                t1 = max(nums1[x1], nums2[y1])
            if x2 not in range(n):
                t2 = nums2[y2]
            elif y2 not in range(m):
                t2 = nums1[x2]
            else:
                t2 = min(nums1[x2], nums2[y2])
            return (t1+t2)/2

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
