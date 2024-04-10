#!/usr/bin/python3
"""Input stats"""

import sys

logs = 0
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


def print_statistics(statuses, total):
    print(f"File size: {total}")
    for element in statuses.items():
        if element[1] != 0:
            print(f"{element[0]}: {element[1]}")


try:
    for line in sys.stdin:
        new_line = line.rstrip().split(" ")
        try:
            logs += 1
            filtering_by_status[new_line[-2]] += 1
            total_size += int(new_line[-1])
            if logs % 10 == 0 and logs != 0:
                print_statistics(filtering_by_status, total_size)
        except BaseException:
            pass
finally:
    print_statistics(filtering_by_status, total_size)
