#!/usr/bin/python3


def canUnlockAll(boxes):
    ''' Function that checks if all boxes are unlocked or not '''
    check = []
    check.insert(0, True)
    for i in range(len(boxes) - 1):
        before = i-1
        after = i+1
        if after in boxes[i]:
            check.insert(after, True)
        elif before in boxes[i]:
            check.insert(before, True)
        else:
            check.insert(after, False)
    if False in check:
        return False
    return True
