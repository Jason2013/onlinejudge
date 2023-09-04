#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    # Write your code here
    maxn = arr[0]
    minn = arr[0]
    sumn = arr[0]

    for i in range(1, 5):
        if arr[i] > maxn:
            maxn = arr[i]
        elif arr[i] < minn:
            minn = arr[i]
        sumn += arr[i]

    print("%d %d" % (sumn - maxn, sumn - minn))

if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
