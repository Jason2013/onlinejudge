class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return findMedianSortedArray(nums2);
        }
        if (nums2.empty()) {
            return findMedianSortedArray(nums1);
        }
        size_t n = nums1.size();
        size_t m = nums2.size();
        size_t half = (n + m)/2;
        size_t low = 0;
        size_t high = (n < half) ? n : half;
        while (low <= high) {
            size_t x = (low + high)/2;
            size_t y = half - x;
            if (y > m) {
                low = x + 1;
                continue;
            }
            if (x > 0 and x < n) {
                if (y > 0 and y < m) {
                    if (nums1[x-1] > nums2[y]) {
                        high = x - 1;
                    }
                    else {
                        if (nums2[y-1] > nums1[x]) {
                            low = x + 1;
                        }
                        else {
                            return findResult(nums1, n, x, nums2, m, y);
                        }
                    }
                }
                else if (y == m) {
                    if (nums2[y-1] > nums1[x]) {
                        low = x + 1;
                    }
                    else {
                        return findResult(nums1, n, x, nums2, m, y);
                    }
                }
                else if (y == 0) {
                    if (nums1[x-1] > nums2[y]) {
                        high = x - 1;
                    }
                    else {
                        return findResult(nums1, n, x, nums2, m, y);
                    }
                }
            }
            else if (x == n) {
                if (nums1[x-1] > nums2[y]) {
                    high = x - 1;
                }
                else {
                    return findResult(nums1, n, x, nums2, m, y);
                }
            }
            else { // x == 0
                if (nums2[y-1] > nums1[x]) {
                    low = x + 1;
                }
                else {
                    return findResult(nums1, n, x, nums2, m, y);
                }
            }
        }
    }
        // if not nums1:
        //     return self.findMedianSortedArray(nums2)

        // if not nums2:
        //     return self.findMedianSortedArray(nums1)

        // n = len(nums1)
        // m = len(nums2)

        // half = (n + m)//2

        // low = 0
        // high = min(n, half)
        // while low <= high:
        //     x = (low + high)//2
        //     y = half - x # number of nums2
        //     if y > m:
        //         low = x + 1
        //         continue

        //     if x > 0 and x < n:
        //         if y > 0 and y < m:
        //             if nums1[x-1] > nums2[y]:
        //                 high = x - 1
        //             else:
        //                 if nums2[y-1] > nums1[x]:
        //                     low = x + 1
        //                 else:
        //                     return self.findResult(nums1, n, x, nums2, m, y)
        //         elif y == m:
        //             if nums2[y-1] > nums1[x]:
        //                 low = x + 1
        //             else:
        //                 return self.findResult(nums1, n, x, nums2, m, y)
        //         elif y == 0:
        //             if nums1[x-1] > nums2[y]:
        //                 high = x - 1
        //             else:
        //                 return self.findResult(nums1, n, x, nums2, m, y)
        //     elif x == n:
        //         if nums1[x-1] > nums2[y]:
        //             high = x - 1
        //         else:
        //             return self.findResult(nums1, n, x, nums2, m, y)
        //     else: # x == 0:
        //         if nums2[y-1] > nums1[x]:
        //             low = x + 1
        //         else:
        //             return self.findResult(nums1, n, x, nums2, m, y)

    // def findResult(self, nums1, n, x, nums2, m, y):
    //     odd = (n + m) % 2 == 1
    //     if odd:
    //         if x == n:
    //             return nums2[y]
    //         if y == m:
    //             return nums1[x]
    //         return min(nums1[x], nums2[y])
    //     else:
    //         if x == 0:
    //             t1 = nums2[y-1]
    //         elif y == 0:
    //             t1 = nums1[x-1]
    //         else:
    //             t1 = max(nums1[x-1], nums2[y-1])
    //         if x == n:
    //             t2 = nums2[y]
    //         elif y == m:
    //             t2 = nums1[x]
    //         else:
    //             t2 = min(nums1[x], nums2[y])
    //         return (t1+t2)/2

    static double min(double a, double b) {
        return a < b ? a : b;
    }
    static double max(double a, double b) {
        return a > b ? a : b;
    }
    static double findResult(const vector<int>& nums1, size_t n, size_t x, const vector<int>& nums2, size_t m, sizt_t y) {
        if ((n + m) % 2 != 0) { // odd
            if (x == n) {
                return nums2[y];
            }
            if (y == m) {
                return nums1[x];
            }
            return min(nums1[x], nums2[y]);
        }
        else {
            double t1, t2;
            if (x == 0) {
                t1 nums2[y-1];
            }
            else if (y == 0) {
                t1 = nums1[x-1];
            }
            else {
                t1 = max(nums1[x-1], nums2[y-1]);
            }
            if (x == n) {
                t2 = nums2[y];
            }
            else if (y == m) {
                t2 = nums1[x];
            }
            else {
                t2 = min(nums1[x], nums2[y]);
            }
            return (t1 + t2)/2.0;
        }
    }
    // def findMedianSortedArray(self, nums):
    //     length = len(nums)
    //     if length % 2 == 1: # Odd
    //         return nums[length//2]
    //     else: # Even
    //         right = length//2
    //         left = right - 1
    //         return (nums[left] + nums[right])/2
    static double findMedianSortedArray(const vector<int>& nums) {
        size_t length = nums.size();
        if (length % 2 == 1) {
            return nums[length/2]
        }
        else {
            size_t right = length/2;
            size_t left = right - 1;
            return (nums[left] + nums[right])/2.0;
        }
    }
}

int main() {
    Solution solution;

    {
        vector<int> nums{1};
        assert(solution.findMedianSortedArray(nums) == 1.0);
    }
    {
        vector<int> nums{1, 2};
        assert(solution.findMedianSortedArray(nums) == 1.5);
    }
    {
        vector<int> nums1{1, 3};
        vector<int> nums2{2};
        assert(solution.findMedianSortedArrays(nums1, nums2) == 2);
    }
    {
        vector<int> nums1{1, 2};
        vector<int> nums2{3, 4};
        assert(solution.findMedianSortedArrays(nums1, nums2) == 2.5);
    }
    {
        vector<int> nums1{0, 0};
        vector<int> nums2{0, 0};
        assert(solution.findMedianSortedArrays(nums1, nums2) == 0.0);
    }
    {
        vector<int> nums1{1};
        vector<int> nums2;
        assert(solution.findMedianSortedArrays(nums1, nums2) == 1.0);
    }
    {
        vector<int> nums1{};
        vector<int> nums2{2};
        assert(solution.findMedianSortedArrays(nums1, nums2) == 2.0);
    }
}
//class TestSolution(unittest.TestCase):
//
//    def setUp(self):
//        self.solution = Solution()
//
//    def test_findMedianSortedArray1(self):
//        nums = [1]
//        res = self.solution.findMedianSortedArray(nums)
//        self.assertEqual(res, 1)
//
//    def test_findMedianSortedArray2(self):
//        nums = [1, 2]
//        res = self.solution.findMedianSortedArray(nums)
//        self.assertEqual(res, 1.5)
//
//    def test_case1(self):
//        nums1 = [1, 3]
//        nums2 = [2]
//        res = self.solution.findMedianSortedArrays(nums1, nums2) 
//        self.assertEqual(res, 2)
//
//    def test_case2(self):
//        nums1 = [1, 2]
//        nums2 = [3, 4]
//        res = self.solution.findMedianSortedArrays(nums1, nums2) 
//        self.assertEqual(res, 2.5)
//
//    def test_case3(self):
//        nums1 = [0, 0]
//        nums2 = [0, 0]
//        res = self.solution.findMedianSortedArrays(nums1, nums2) 
//        self.assertEqual(res, 0)
//
//    def test_case4(self):
//        nums1 = []
//        nums2 = [1]
//        res = self.solution.findMedianSortedArrays(nums1, nums2) 
//        self.assertEqual(res, 1)
//
//    def test_case5(self):
//        nums1 = [2]
//        nums2 = []
//        res = self.solution.findMedianSortedArrays(nums1, nums2) 
//        self.assertEqual(res, 2)
//
//if __name__ == '__main__':
//    unittest.main()
//};
