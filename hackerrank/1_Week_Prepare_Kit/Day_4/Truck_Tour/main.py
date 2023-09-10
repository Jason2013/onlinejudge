#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'truckTour' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
#

def truckTour(petrolpumps):
    #print(petrolpumps)
    # Write your code here
    n = len(petrolpumps)
    #for start in range(n):
    start = 0
    while start < n:
        end = n-1 if start == 0 else start - 1
        tank = 0
        for i in range(n):
            pump = start + i
            if pump > n -1:
                pump -= n
            tank += petrolpumps[pump][0] - petrolpumps[pump][1]
            #print(tank, petrolpumps[pump])
            if tank < 0:
                #if pump < 
                start += pump + 1
                break
        if pump == end:
            #print(start)
            return start

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    petrolpumps = []

    for _ in range(n):
        petrolpumps.append(list(map(int, input().rstrip().split())))

    result = truckTour(petrolpumps)

    fptr.write(str(result) + '\n')

    fptr.close()
