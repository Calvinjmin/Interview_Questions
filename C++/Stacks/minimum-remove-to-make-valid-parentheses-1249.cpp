// Valid Parentheses Sister Question - [Leetcode 1249](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses)

using namespace std;

#include<stack>

string minRemoveToMakeValid(string s) {
    // Using a stack, post all invalid parenth indicies
    stack<int> st;

    for ( int i = 0; i < s.size(); i++ ) {
        if ( s[i] == '(' ) {
            st.push(i);
        }
        else if ( s[i] == ')' ) {
            if ( !st.empty() ) st.pop(); // Valid Closing
            else s[i] = '%';
        }
    }

    // Invalid Openings left in the stack
    while ( !st.empty() ) {
        s[st.top()] = '%';
        st.pop();
    }

    string ans = "";
    for ( int i = 0; i < s.size(); i++ ) {
        if ( s[i] != '%' ) {
            ans.push_back(s[i]);
        }
    }
    return ans;
}
