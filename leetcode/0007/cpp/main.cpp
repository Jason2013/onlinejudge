#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {

#define INTMIN (1 << 31)
#define INTMAX (~INTMIN)

#define INTMIN_LAST (INTMIN % 10)
#define INTMAX_LAST (INTMAX % 10)

        int result = 0;

        while (x != 0)
        {
            int remain = x % 10;
            x /= 10;

            if (((result > INTMAX / 10) || (result == INTMAX / 10 && remain > INTMAX_LAST)) ||
                ((result < INTMIN / 10) || (result == INTMIN / 10 && remain < INTMIN_LAST)))
            {
                // overflow
                return 0;
            }


            result = result * 10 + remain;
        }

        return result;
    }
};

int main()
{
    Solution s;

    assert(s.reverse(123) == 321);
    assert(s.reverse(-123) == -321);
    assert(s.reverse(120) == 21);
    assert(s.reverse(1534236469) == 0);
    assert(s.reverse(INTMIN) == 0);

    return 0;
}
