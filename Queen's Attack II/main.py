#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'queensAttack' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER r_q
#  4. INTEGER c_q
#  5. 2D_INTEGER_ARRAY obstacles
#

def queensAttack(n, k, r_q, c_q, obstacles):
    attacks=0
    for x in range (-1,2):
        for y in range (-1,2):
            temp_loc=[r_q+x,c_q+y]
            if(x==0 and y==0):
                continue
            print("current x ",x," current y ",y)
            while((temp_loc[0]<=n and temp_loc[0]>0) and 
            (temp_loc[1]<=n and temp_loc[1]>0)):
                if(check_obstacles(temp_loc[0],temp_loc[1],obstacles)):
                    break;
                else:
                    print("attack found at: ",temp_loc[0]," ",temp_loc[1])
                    temp_loc[0]+=x
                    temp_loc[1]+=y
                    attacks+=1
                    
    return attacks
                
            
    
def check_obstacles(x,y,obstacles):
    for i in obstacles:
        if i[0]==x and i[1]==y:
            return True
    return False

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    r_q = int(second_multiple_input[0])

    c_q = int(second_multiple_input[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    result = queensAttack(n, k, r_q, c_q, obstacles)

    fptr.write(str(result) + '\n')

    fptr.close()
