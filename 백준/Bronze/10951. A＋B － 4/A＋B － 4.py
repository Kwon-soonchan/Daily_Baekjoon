import sys

inputs = sys.stdin.readlines()

for Input in inputs:
    A, B = map(int, Input.split())
    print(A+B)