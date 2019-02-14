# coding=utf-8

class Solution:
    def longestCommonPrefix(self, strs: 'List[str]') -> 'str':
        prefix = ""
        for x in zip(*strs):
            if all(item == x[0] for item in x):
                prefix += x[0]
            else:
                break
        return prefix

if __name__ == "__main__":
    s = Solution()
    assert s.longestCommonPrefix(["flower", "flow", "flight"]) == "fl"
    assert s.longestCommonPrefix(["flower", "flow", "flight"]) == "fl";
    assert s.longestCommonPrefix(["dog", "racecar", "car"]) == "";
    assert s.longestCommonPrefix(["dog", "racecar", ""]) == "";
    assert s.longestCommonPrefix(["", "racecar", "car"]) == "";
    assert s.longestCommonPrefix([]) == "";
    assert s.longestCommonPrefix([""]) == "";
    assert s.longestCommonPrefix(["", ""]) == "";
