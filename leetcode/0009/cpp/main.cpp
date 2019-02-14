#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        if (x < 10)
        {
            return true;
        }

        vector<int> nums;

        while (x != 0)
        {
            int r = x % 10;
            nums.push_back(r);
            x /= 10;
        }

        uint32_t first = 0;
        uint32_t last = static_cast<uint32_t>(nums.size() - 1);
        while (first < last)
        {
            if (nums[first] != nums[last])
            {
                return false;
            }

            ++first;
            --last;
        }

        return true;
    }
};

int main()
{
    Solution s;

    assert(s.isPalindrome(121) == true);
    assert(s.isPalindrome(-121) == false);
    assert(s.isPalindrome(10) == false);
    assert(s.isPalindrome(0) == true);
    assert(s.isPalindrome(1) == true);
    assert(s.isPalindrome(11) == true);

    return 0;
}
