#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#

def minimumBribes(q):
    # Write your code here
    #print("(", q, ")")
    br = 0
    for pos in range(len(q)):
        diff = q[pos] - pos - 1
        if diff > 2:
            print("Too chaotic")
            return

    r = 0        
    for i in range(1, len(q)):
        j = i - 1
        while j >= 0:
            if q[j] > q[j+1]:
                q[j],q[j+1]=q[j+1],q[j]
                r +=1
            
                j -= 1
            else:
                break
            

            
        #for p in range(pos):
         #   if q[p] > q[pos]:
          #      br +=1
        #if diff > 0:
        #    br += diff
        #print("br=",br," diff=",diff)
    print(r)
            

if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
