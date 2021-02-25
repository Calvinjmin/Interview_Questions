/*
LEETCODE PROBLEM: https://leetcode.com/problems/sqrtx/

Description: Given a non-negative integer, compute and return the square root of the number.

Basic Solution: Use the Math Class' square root function to compute an answer (as a double).
                Type cast the number to an int and return it.

*/

public class mySqrt {
    public int mySqrt(int x) {
        return (int)Math.sqrt(x);
    }
}
