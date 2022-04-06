/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 * 选择1 or 2不重要，重要的是n有多数种选法
 */


// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return n;
        // vector<int> dp(n + 1);
        // dp[0] = 0; dp[1] = 1; dp[2] = 2;        
        // for(int i = 3; i <= n; ++i) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        
        // f(n) = f(n-1) + f(n-2)
        // f(n-1) = b, f(n-2) = a;
        int a = 1, b = 2, c = 2;
        for(int i = 3; i <=n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
// @lc code=end

