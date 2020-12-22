#include <vector>
#include <cassert>
using namespace std;
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
            if (x > 0 && x < n) {
                if (y > 0 && y < m) {
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
                else {
                    low = x + 1;
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
        return 0.0;
    }
    static double min(double a, double b) {
        return a < b ? a : b;
    }
    static double max(double a, double b) {
        return a > b ? a : b;
    }
    static double findResult(const vector<int>& nums1, size_t n, size_t x, const vector<int>& nums2, size_t m, size_t y) {
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
                t1 = nums2[y-1];
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
    static double findMedianSortedArray(const vector<int>& nums) {
        size_t length = nums.size();
        if (length % 2 == 1) {
            return nums[length/2];
        }
        else {
            size_t right = length/2;
            size_t left = right - 1;
            return (nums[left] + nums[right])/2.0;
        }
    }
};

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
