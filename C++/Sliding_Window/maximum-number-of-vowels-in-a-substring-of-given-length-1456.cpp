// O(1) Vector Lookup with Sliding Window - [Leetcode 1456](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length)

#include<vector>

int maxVowels(string s, int k) {
    // O(1) lookup
    vector<int> vowel(26,0);
    vowel[0] = 1;
    vowel['e'-'a'] = 1;
    vowel['i'-'a'] = 1;
    vowel['o'-'a'] = 1;
    vowel['u'-'a'] = 1;

    int left = 0, right = k;
    int ans = 0;
    for ( int i = 0; i < k; i++ ) {
        if (vowel[s[i]-'a'] == 1) ans += 1 ;
    }

    int result = ans;
    while ( right < s.length() ) {
        if ( vowel[s[left]-'a'] == 1 ) {
           ans -=1; 
        }
        if ( vowel[s[right]-'a'] == 1 ) {
            ans += 1;
        }
        left++;
        right++;
        result = max(result, ans);
    }
    return result;
}
