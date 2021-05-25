/*
HACCKERRANK PROBLEM: https://www.hackerrank.com/challenges/java-string-reverse/problem

Description: Given a string, determine if it is a palindrome

Basic Solution: Recursive solution that compares the first and last letter
                    of the given string.

 */
import java.io.*;
import java.util.*;

public class String_Reverse {

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        boolean pal = isPalindrome(A);
        if ( pal ) {
            System.out.println( "Yes" );
        }
        else {
            System.out.println("No");
        }
    }

    public static boolean isPalindrome( String s ) {
        if ( s.length() < 2 ) {
            return true;
        }
        if ( s.charAt(0) == s.charAt(s.length() - 1 ) ) {
            return isPalindrome( s.substring(1, s.length() -1 ));
        }
        else {
            return false;
        }
    }
}
