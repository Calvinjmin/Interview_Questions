// Principles of being a factor - [Leetcode 1492](https://leetcode.com/problems/the-kth-factor-of-n/description/)

int kthFactor(int n, int k) {
    int factorIndex = 0;
    for ( int i = 1; i <= n; i++ ) {
        if ( n % i == 0 ) {
            factorIndex += 1;
        }
        if ( factorIndex == k ) {
            return i;
        }
    }
    return -1;
}