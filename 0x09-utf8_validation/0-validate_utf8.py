#!/usr/bin/python3
""" Init the file """


def validUTF8(data):
    """ validate utf-8 in data comming """
    binary_10 = 0
    for code in data:
        code = '{0:08b}'.format(code)[-8:]
        if binary_10 != 0:
            binary_10 -= 1
            if not code.startswith('10'):
                return False
        elif code[0] == '1':
            binary_10 = len(code.split('0')[0])
            if binary_10 == 1 or binary_10 > 4:
                return False
            binary_10 -= 1
    if binary_10 != 0:
        return False
    return True
