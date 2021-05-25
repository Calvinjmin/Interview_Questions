/*
LEETCODE PROBLEM: https://leetcode.com/problems/fizz-buzz/

Description: If a number is divisble by both 3 and 5, replace with "FizzBuzz",
                If a number is only divisible by 3, then replace with "Fizz",
                If a number is only divisible by 5, then replace with "Buzz"

Basic Solution: Iterate through the given int, and use three boolean statments
                    to see if the number fits the given criteria.

 */

import java.io.*;
import java.util.*;

class Solution {
    public static List<String> fizzBuzz(int n) {
        List<String> list = new ArrayList<String>();
        for ( int i = 1; i < n + 1; i++ ) {
            boolean fizz = ( i % 3 == 0);
            boolean buzz = ( i % 5 == 0 );
            if ( fizz && buzz ) {
                list.add("FizzBuzz");
            }
            else if ( buzz ) {
                list.add("Buzz");
            }
            else if ( fizz ) {
                list.add("Fizz");
            }
            else {
                list.add(i + "");
            }
        }
        return list;
    }

    public static void main( String [] args ) {
        System.out.print( "Input Number: " );
        Scanner sc=new Scanner(System.in);
        String num =sc.next();
        List<String> temp = fizzBuzz( Integer.parseInt(num) );
        for ( String x : temp ) {
            System.out.println(x);
        }
    }
}