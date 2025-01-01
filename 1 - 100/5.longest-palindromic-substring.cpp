/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#define longestPalindrome longest_palindrome

class Solution {
  public:
    /**
     * T = O(n ^ 2)
     * S = O(1)
     * 
     * n = size of string
    */
    string longest_palindrome(string s) {
        int n = s.length();
        int l = 0, r = 0;

        for (int i = 0; i < n - 1; i++) {
            int odd_len = find_palindrome_length(s, i, i);
            int even_len = find_palindrome_length(s, i, i + 1);

            int len = max(even_len, odd_len);

            if (len > r - l + 1) {
                l = i - (len - 1) / 2;
                r = i + (len / 2);
            }
        }

        return s.substr(l, r - l + 1);
    }

    int find_palindrome_length(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }

        return r - l - 1;
    }
};
// @lc code=end
