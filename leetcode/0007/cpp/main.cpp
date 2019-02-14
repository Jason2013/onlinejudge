#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        int result = 0;
        int remain = 0;

        if (x < 0)
        {
            x = -x;
            flag = -1;
        }

        while (x != 0)
        {
            remain = x % 10;
            x /= 10;

            if (result > 214748364 || (result == 214748364 && remain >= 8))
            {
                // overflow
                return 0;
            }

            result = result * 10 + remain;
        }

        return result * flag;
    }
};

int main()
{
    Solution s;

    assert(s.reverse(123) == 321);
    assert(s.reverse(-123) == -321);
    assert(s.reverse(120) == 21);
    assert(s.reverse(1534236469) == 0);

    return 0;
}
