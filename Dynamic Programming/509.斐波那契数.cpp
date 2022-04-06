/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        // a，b分别记录前面第二个和第一个状态的值
        int a = 0, b = 1, c = 1;

        for(int i = 1; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
// @lc code=end

