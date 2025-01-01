/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#define twoSum two_sum

class Solution {
  public:
    /**
     * T = O(n)
     * S = O(n)
     * 
     * n = size of nums array
     */
    vector<int> two_sum(vector<int>& nums, int target) {
        int n = nums.size();
        int complement;

        vector<int> result(2, -1);

        map<int, int> position;

        for (int i = 0; i < n; i++) {
            complement = target - nums[i];

            if (position.find(complement) != position.end()) {
                result[0] = position[complement];
                result[1] = i;

                return result;
            }

            position[nums[i]] = i;
        }

        return result;
    }
};
// @lc code=end
