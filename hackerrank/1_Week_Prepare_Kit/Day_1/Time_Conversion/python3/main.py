#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    hs = s[:2]
    ms = s[2:8]
    ap = s[8:]

#    print("hs=", hs)
#    print("ms=", ms)
#    print("ap=", ap)

    hh = int(hs)

    if ap == "AM":
        if hh == 12:
            hs = "00"
    else: # "PM"
        if hh < 12:
            hs = str(hh + 12)

    return hs + ms


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
