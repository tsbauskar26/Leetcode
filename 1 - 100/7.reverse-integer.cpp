/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
  public:
    /**
     * T = O(log(x))
     * S = O(1)
     */
    int reverse(int x) {
        int ans = 0;

        while (x) {
            int unit = x % 10;

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && unit > INT_MAX % 10)) {
                return 0;
            }

            if (ans < INT_MIN / 10 ||
                (ans == INT_MIN / 10 && unit < INT_MIN % 10)) {
                return 0;
            }

            ans = (ans * 10) + unit;
            x = x / 10;
        }

        return ans;
    }
};
// @lc code=end
