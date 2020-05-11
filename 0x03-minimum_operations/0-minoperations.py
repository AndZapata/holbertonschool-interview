#!/usr/bin/python3
''' File init '''


def minOperations(n):
    ''' Functions to find the minimum times to copy and paste '''
    if not n or n < 2:
        return 0
    count = 0
    idx = 2
    while idx <= n:
        if n % idx == 0:
            count += idx
            n = n // idx
        else:
            idx += 1
    return count

if __name__ == "__main__":
    minOperations()
