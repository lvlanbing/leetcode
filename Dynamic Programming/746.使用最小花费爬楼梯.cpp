/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        // dp[i]为n=i时的最小费用
        // dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
        // cost[i]为从当前阶段所需要的费用
        dp[0] = 0; dp[1] = 0; dp[2] = min(cost[0], cost[1]);
        for(int i = 3; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
        }
        return dp[n];        
    }
};
// @lc code=end

