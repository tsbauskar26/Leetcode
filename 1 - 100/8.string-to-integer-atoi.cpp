/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#define myAtoi my_atoi

class Solution {
  public:
    /**
     * T = O(n)
     * S = O(1)
     * 
     * n = length of string
     */
    int my_atoi(string s) {
        int n = s.length();
        int i = 0;

        int ans = 0, sign = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (s[i] == '+' || s[i] == '-') {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int unit = s[i] - '0';

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && unit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = (ans * 10) + unit;
            i++;
        }

        return ans * sign;
    }
};
// @lc code=end
