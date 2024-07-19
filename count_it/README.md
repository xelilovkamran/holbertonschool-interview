# Count it!

<!-- write docs for 0-count.py file -->

## Description of the project

This project was created with learning purposes, to understand how to count the number of lines in a file.

## Description of the function

The function `def count_lines(filename="", line_number=0):` receives a filename and a line_number as arguments. It reads the file and counts the number of lines in it. If the line_number is greater than the number of lines in the file, it returns the total number of lines in the file. If the line_number is less or equal to 0, it returns 0.

## Description of the file

The file `0-count.py` contains the function `def count_lines(filename="", line_number=0):` that counts the number of lines in a file.

## Example

```python
>>> count_lines("README.md", 1)
1
>>> count_lines("README.md", 0)
0
>>> count_lines("README.md", 10)
3
>>> count_lines("README.md", -1)
0
```
