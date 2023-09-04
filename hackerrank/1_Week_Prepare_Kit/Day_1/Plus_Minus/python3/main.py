#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    p = 0
    n = 0
    z = 0
    for v in arr:
        if v > 0:
            p += 1
        elif v < 0:
            n += 1
        else:
            z += 1

    s = p + n + z
    print(round(p/s, 6))
    print(round(n/s, 6))
    print(round(z/s, 6))


if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)

