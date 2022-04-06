/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        //初始化动态数组
        if(obstacleGrid[0][0] == 0) dp[0][0] = 1;
        else dp[0][0] = 0; 
        for(int i = 1; i < m; ++i) {
            //如果前一个有障碍，则后面的也达不到
            dp[i][0] = dp[i - 1][0];
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            }
        }
        for(int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i - 1];
            if(obstacleGrid[0][i] == 1)
                dp[0][i] = 0;
        }


        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                
                dp[i][j] = dp[i-1][j] + dp[i][j - 1];
                //把有障碍的地方，设置为不可达
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

