#!/usr/bin/python3
""" Inirialize the file """


def validUTF8(data):
    """ validate utf-8 in data comming """
    binary_10 = 0
    for code in data:
        code = bin(code).replace('0b', '').rjust(8, '0')
        if binary_10 != 0:
            binary_10 -= 1
            if not code.startswith('10'):
                return False
        elif code[0] == '1':
            binary_10 = len(code.split('0')[0]) - 1
    return True
