"""
HACKERRANK PROBLEM: https://www.hackerrank.com/challenges/python-tuples/problem

Description of the problem: Compute the hash of a tuple, given a list of integers

Basic Solution: Use the mapping function to create a list and covert it into a tuple
"""

if __name__ == '__main__':
    n = int(input())
    integer_list = map(int, input().split())

temp_list = map(int, integer_list)
t = tuple(temp_list)
print(hash(t))