#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t n = nums1.size();
        size_t m = nums2.size();

        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        size_t half = (n + m)/2;
        size_t low = 0;
        size_t high = n;
        size_t x, y;
        while (low <= high) {
            x = (low + high)/2;
            y = half - x;

            if (x > 0 && nums1[x-1] > nums2[y])
                high = x - 1;
            else if (x < n && nums2[y-1] > nums1[x])
                low = x + 1;
            else
                break;
        }

        float t1, t2;
        if (x == n)
            t2 = nums2[y];
        else if (y == m)
            t2 = nums1[x];
        else
            t2 = std::min(nums1[x], nums2[y]);

        if ((n + m) & 1) // odd
            return t2;

        if (x == 0)
            t1 = nums2[y-1];
        else if (y == 0)
            t1 = nums1[x-1];
        else
            t1 = std::max(nums1[x-1], nums2[y-1]);

        return (t1+t2)/2.0f;
    }
};

int main() {
    Solution solution;
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
