/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:

    //回溯
    // int MAX = 0;
    // int sum = 0, num = 1;
    // void backtracking(int n, int start) {
    //     if(sum == n) {
    //         if(MAX < num) {
    //             MAX = num;
    //         }
    //         return;
    //     } else if(sum > n) return;
                                    //减枝操作
    //     for(int i = start; i <= n - sum; ++i) {
    //         sum += i;
    //         num = num * i;
    //         backtracking(n, i);
    //         sum -= i;
    //         num = num / i;
    //     }
    // }

    // void dfs(int cur, int maxnum, int target) {
    //     if(target == 0) {
    //         if(num > MAX) {
    //             MAX = num;
    //         }
    //         return;
    //     }
    //     if(target < 0 || cur == maxnum+1)
    //         return;
    //     if(target >= cur) {
    //         num *= cur;
    //         dfs(cur, maxnum, target - cur);
    //         num /= cur;
    //     }
    //     dfs(cur + 1, maxnum, target);
    // }

    int integerBreak(int n) {
        // vector<int> nums(n);
        // if(n == 2) return 1;
        // if(n == 3) return 2;
        // backtracking(n, 1);

        // dfs(1, n - 1, n);

        // 方法数值
        // if(n == 2) return 1;
        // if(n == 3) return 2;
        // int MAX = 0;
        // //拆分成2，3，4，5个，判断余数加到除数上，还是余数单独使用
        // for(int i = 2; i <= n; ++i) {
        //     int num = n / i;
        //     int mod = n % i;
        //     int temp = 1;
        //     if(mod != 0) {
        //         temp = max(pow(i, num - 1) * (i + mod), pow(i, num) * mod);
        //     } else {
        //         temp = pow(i, num);
        //     }
        //     if(temp > MAX) {
        //         MAX = temp;
        //     }
        // }
        // return MAX;
        
        //方法dp
        // 拆分数值（下标）得到的最大乘积
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 3; i <= n; ++i) {
            for(int j = 1; j < i - 1; ++j) {
                dp[i] = max(dp[i], max((i - j)*j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

