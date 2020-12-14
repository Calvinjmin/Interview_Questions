"""
HACKERRANK PROBLEM: https://www.hackerrank.com/challenges/py-introduction-to-sets/problem

Description of the problem: Compute the average of the given array using sum() and len()

Basic Solution: Change the array into a set and use the given functions
"""

def average(array):
    return sum(set(array))/len(set(array))

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)