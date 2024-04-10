#!/usr/bin/python3
"""Reads stdin line by line and computes metrics
If count of lines is evenly divided by 10 and/or
keyboardinterrupt
all info will be printed"""

import sys

logs = []
total_size = 0
filtering_by_status = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


def print_msg():
    """Prints the stats"""
    print(f"File size: {total_size}")
    for element in filtering_by_status.items():
        if element[1] != 0:
            print(f"{element[0]}: {element[1]}")


try:
    for line in sys.stdin:
        line = line.strip()
        logs.append(line)
        line = line.split(" ")
        filtering_by_status[line[-2]] += 1
        total_size += int(line[-1])
        if len(logs) % 10 == 0 and len(logs) != 0:
            print_msg()

except KeyboardInterrupt:
    print_msg()
