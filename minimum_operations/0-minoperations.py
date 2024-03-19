#!/usr/bin/python3

"""
Main file for testing
"""


def minOperations(n):
    if n == 1 or n <= 0:
        return 0

    operations = 0
    number = n
    isNotDivided = False
    string = 0

    while True:
        for i in range(2, int(number / 2) + 2):
            if number % i == 0 and number != i:
                number /= i
                isNotDivided = False
            else:
                isNotDivided = True

        if isNotDivided and number == n:
            number = 1
            break
        elif isNotDivided and number != n:
            break

    if isNotDivided:
        operations += number
        string += operations

        while n % number == 0 and n != string:

            if number % string == 0:
                operations += 2
            else:
                operations += 1
            string += number

            if (n % (number + string)) != 0:
                number = string

    return int(operations)
