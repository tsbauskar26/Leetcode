/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#define isPalindrome is_palindrome

class Solution {
  public:
    /**
     * T = O(log(x))
     * S = O(1)
     */
    bool is_palindrome(int num) {
        int x = num;
        int ans = 0;

        if (x < 0) {
            return false;
        }

        while (x) {
            int unit = x % 10;

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && unit > INT_MAX % 10)) {
                return false;
            }

            ans = (ans * 10) + unit;
            x = x / 10;
        }

        return ans == num;
    }
};
// @lc code=end
