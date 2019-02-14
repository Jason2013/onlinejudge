#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;

        uint32_t pos = 0;
        while (pos <= strs[0].size() - 1)
        {
            char c = strs[0][pos];
            for (uint32_t si = 1; si < static_cast<uint32_t>(strs.size()); si++)
            {
                if (pos > strs[si].size() - 1 || strs[si][pos] != c)
                {
                    return prefix;
                }
            }

            prefix += c;
            ++pos;
        }

        return prefix;
    }
};

int main()
{
    Solution s;

    assert(s.longestCommonPrefix(vector<string>{"flower", "flow", "flight"}) == "fl");
    assert(s.longestCommonPrefix(vector<string>{"dog", "racecar", "car"}) == "");
    assert(s.longestCommonPrefix(vector<string>{"dog", "racecar", ""}) == "");
    assert(s.longestCommonPrefix(vector<string>{"", "racecar", "car"}) == "");

    return 0;
}
