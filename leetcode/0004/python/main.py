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

#        if n < m:
#            nums1, nums2 = nums2, nums1
#            n, m = m, n
#
#        if n == 1 and m == 1:
#            return (nums1[0] + nums2[0])/2

        length = n + m
        odd = (length % 2) == 1
        half = int(length/2)
#        if length % 2 == 1:
#            half = int(length/2)
#            odd = True
#        else:
#            half = int(length/2) - 1
#            odd = False

        low = 0
        high = half
        #x = half/2 # number of nums1
        #while x >= 0 and x <= half:
        while True:
            x = (low + high)/2
            if x < 0 or x > high:
                break
            x = int(x)
            y = half - x # number of nums2
            #assert x + y == half
            if x > n:
                high = x - 1

                #x = int((x-1)/2) # decrease x
                continue
            if y > m:
                low = x + 1
                #x = int((x+1+half)/2) # increase x
                continue
            x1 = x-1
            x2 = x
            y1 = y-1
            y2 = y
# 
            #if x1 == n - 1:
            if x == n:
                pass
                #if y == 0:
                if nums1[x1] <= nums2[y2]:
                    return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
                else:
                    high = x - 1
                    #x = decrease(x)
#                pass
#                elif y < m:
#                    if nums1[x1] <= nums2[x2]:
#                        return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
#                    else:
#                        x = decrease(x)
#                    pass
#                    
#                    pass
#                else:
#                    assert False # impossible
            #elif x2 == 0:
            elif x == 0:
                if nums2[y1] <= nums1[x2]:
                    return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
                else:
                    low = x + 1
                    #x = increase(x, half)
                # pass
            else:
                assert x > 0 and x < n
                if y == m:
                    if nums2[y1] <= nums1[x2]:
                        return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
                    else:
                        low = x + 1
                        #x = increase(x)
                    pass
                elif y == 0:
                    if nums1[x1] <= nums2[y2]:
                        return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
                    else:
                        #x = decrease(x)
                        high = x - 1
                    pass
                else:
                    if nums1[x1] <= nums2[y2]:
                        if nums2[y1] <= nums1[x2]:
                            return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
                        else:
                            #x = increase(x)
                            low = x + 1
                    else:
                        assert nums1[x1] > nums2[y2]
                        #x = decrease(x)
                        high = x - 1
                    # assert y > 0 and y < m
                    # pass
                # pass

            # if x1 in range(n) and y2 in range(m):
            #     if nums1[x1] <= nums2[y2]:
            #         return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
            #     else:
            #         x = int((x-1)/2) # decrease x
            #         continue
            # if x2 in range(n) and y1 in range(m):
            #     if nums2[y1] <= nums1[x2]:
            #         return self.findResult(odd, nums1, n, x1, x2, nums2, m, y1, y2)
            #     else:
            #         x = int((x+1+half)/2) # increase x
            #         continue

            # assert False

#                    if odd:
#                        return (nums1[x2] if x2 in range(n) else 0)
##
#            assert y >= 0 and y < m
#            if nums1[x] <= nums2[y+1]:
#                if y == m - 1 or nums2[y] <= nums1[x+1]:
#                    if odd:
#                        if x2 not in range(n):
#                            return nums2[y2]
#                        if y2 not in range(m):
#                            return nums1[x2]
#                        return min(nums1[x2], nums2[y2])
#                        #/* assert False */
#                        #/* return nums1[x] */
#                    else:
#                        if x1 not in range(n):
#                            t1 = nums2[y1]
#                        elif y1 not in range(m):
#                            t1 = nums1[x1]
#                        else:
#                            t1 = max(nums1[x1], nums2[y1])
#                        if x2 not in range(n):
#                            t2 = nums2[y2]
#                        elif y2 not in range(m):
#                            t2 = nums1[x2]
#                        else:
#                            t2 = min(nums1[x2], nums2[y2])
#                        return (t1+t2)/2
#
#                        return (max(nums1[x], nums2[y]) + min(nums1[x+1], nums2[y+1]))/2
#                else:
#                    x = int(((x+1) + half)/2)
#                    y = half - x - 1
#            else:
#                x = int((x-1)/2)
#                y = half - x - 1
#
#        assert False
        # nums = sorted(nums1 + nums2)
        # return findMedianSortedArray(nums)

    def increase(val, end):#, val):
        return (val + 1 + end)/2
    def decrease(val):
        return (val - 1)/2
    def findResult(self, odd, nums1, n, x1, x2, nums2, m, y1, y2):
        assert x1 + y1 == int((n + m)/2) - 2
        print (odd, nums1, n, x1, x2, nums2, m, y1, y2)
        if odd:
            #assert not (x2 not in range(n) and y2 not in range(m))
            if x2 not in range(n):
                return nums2[y2]
            if y2 not in range(m):
                return nums1[x2]
            return min(nums1[x2], nums2[y2])
            #/* assert False */
            #/* return nums1[x] */
        else:
            #assert not (x1 not in range(n) and y1 not in range(m))
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

            #return (max(nums1[x], nums2[y]) + min(nums1[x+1], nums2[y+1]))/2

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
