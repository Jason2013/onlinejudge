# coding=utf-8

class Solution:
    def isPalindrome(self, x: 'int') -> 'bool':
        if x < 0:
            return False

        xs = str(x)
        rxs = ''.join((x for x in reversed(xs)))
        return xs == rxs

if __name__ == "__main__":
    s = Solution()

    assert(s.isPalindrome(121) == True);
    assert(s.isPalindrome(-121) == False);
    assert(s.isPalindrome(10) == False);
    assert(s.isPalindrome(0) == True);
    assert(s.isPalindrome(1) == True);
    assert(s.isPalindrome(11) == True);
