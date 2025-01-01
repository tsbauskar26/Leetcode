/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
  public:
    string convert(string s, int rows) {
        if (rows == 1) {
            return s;
        }

        int n = s.length();

        int blocks = ceil(n / (2.0 * (rows - 1)));
        int cols = blocks * (rows - 1);

        vector<vector<char>> grid(rows, vector<char>(cols, '#'));

        int r = 0, c = 0;
        int dr = 1, dc = 0;

        for (char x : s) {
            grid[r][c] = x;

            if (r == rows - 1) {
                dr = -1;
                dc = 1;
            } else if (r == 0) {
                dr = 1;
                dc = 0;
            }

            r = r + dr;
            c = c + dc;
        }

        string ans = "";

        for (vector<char> v : grid) {
            for (char c : v) {
                if (c != '#') {
                    ans.push_back(c);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
