# coding=utf-8

class Solution:
    def isPalindrome(self, x: 'int') -> 'bool':
        if x < 0:
            return False

        xs = str(x)
        first = 0
        last = len(xs) - 1
        while first < last:
            if xs[first] != xs[last]:
                return False
            first += 1
            last -= 1

        return True

if __name__ == "__main__":
    s = Solution()

    assert(s.isPalindrome(121) == True);
    assert(s.isPalindrome(-121) == False);
    assert(s.isPalindrome(10) == False);
    assert(s.isPalindrome(0) == True);
    assert(s.isPalindrome(1) == True);
    assert(s.isPalindrome(11) == True);
