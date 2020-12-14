"""
HACKERRANK PROBLEM: https://www.hackerrank.com/challenges/write-a-function/problem

Description of the problem: Given a year, determine if it is a leap year.

Basic Solution: Use multiple If...Elif...Else statements to cover each leap year attribute given
                    in the descriptionpy of the problem.
"""
def is_leap(year):
    leap = False       #Given Code
    if year % 4 == 0 :           #Covers this case: The year can be evenly divided by 4, is a leap year, unless
        if year % 100 == 0:      #The year can be evenly divided by 100, it is NOT a leap year
            if year % 400 == 0:  #The year is also evenly divisible by 400.
                leap = True
            else:
                leap = False
        else:
            leap = True
    else:
        leap = False
    return leap         #Given Code

year = int(input())     #Given Code
print(is_leap(year))    #Given Code