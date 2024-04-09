#!/usr/bin/python3
"""
program that reads stdin line by line
and computes metrics
"""

import sys
from typing import List, Dict


logs: List[str] = []
total_size: int = 0

filtering_by_status: Dict[str, int] = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


try:
    for line in sys.stdin:
        line = line.strip()
        logs.append(line)
        line = line.split(" ")
        filtering_by_status[line[-2]] += 1
        total_size += int(line[-1])
        if len(logs) % 10 == 0 and len(logs) != 0:
            print(f"File size: {total_size}")
            for element in filtering_by_status.items():
                if element[1] != 0:
                    print(f"{element[0]}: {element[1]}")

except KeyboardInterrupt:
    print(f"File size: {total_size}")
    for element in filtering_by_status.items():
        if element[1] != 0:
            print(f"{element[0]}: {element[1]}")
