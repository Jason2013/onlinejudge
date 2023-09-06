#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    # Write your code here
    r = ""
    for c in s:
        if c >= 'a' and c <= 'z':
            r += chr(ord('a') + ((ord(c) - ord('a') + k) % 26))
        elif c >= 'A' and c <= 'Z':
            r += chr(ord('A') + ((ord(c) - ord('A') + k) % 26))
        else:
            r += c

    return r


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
