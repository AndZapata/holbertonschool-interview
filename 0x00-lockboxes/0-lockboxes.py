#!/usr/bin/python3


def canUnlockAll(boxes):
    ''' Function that checks if all boxes are unlocked or not '''
    check = [None] * len(boxes)
    check[0] = True
    for i in range(1, len(boxes)):
        flag = False
        for j in range(len(boxes)):
            flag = i in boxes[j] and i != j
            if flag != False:
                check[i] = flag
                break
        if flag is False:
            check[i] = flag
    if False in check:
        return False
    return True
