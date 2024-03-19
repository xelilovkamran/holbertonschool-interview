#!/usr/bin/python3

"""
Main file for testing
"""


def minOperations(n):
    if n == 1 or n <= 0:
        return 0
    length = 0
    min_operation = 0
    for i in range(2, n//2+2):
        if n % i == 0:
            min_operation = i
            break

    count = min_operation
    length = min_operation

    while n != length:
        if n % length == 0:
            min_operation = length
            length += min_operation

            count += 2

        else:
            count += 1
            length += min_operation

    return count
