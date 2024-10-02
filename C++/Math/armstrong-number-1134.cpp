// Mod and Power - [Leetcode 1134](https://leetcode.com/problems/armstrong-number)

bool isArmstrong(int n) {
    int numDigits = 0; 
    int copy = n;

    while ( copy > 0 ) {
        copy = copy / 10;
        numDigits += 1;
    }

    int ans = 0;
    copy = n;
    while ( copy > 0 ) {
        ans += pow((copy%10),numDigits);
        copy /= 10;
    }

    return ans == n;
}
};
