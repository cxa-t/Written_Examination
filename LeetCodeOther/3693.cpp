// https://leetcode.cn/problems/climbing-stairs-ii/


class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // 创建 dp 数组，dp[i] 表示到达第 i 阶的最小总代价
        vector<int> dp(n + 1, INT_MAX);
        // 到达第 0 阶不需要任何代价
        dp[0] = 0;
        // 从第 1 阶开始，依次计算到达每一阶的最小代价
        for (int i = 1; i <= n; i++) {
            // 枚举可以跳到第 i 阶的前置台阶，最多往前看 3 阶
            for (int j = max(0, i - 3); j < i; j++) {
                // 从第 j 阶跳到第 i 阶，跳跃代价为 (i - j)^2
                dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
            }
            // 到达第 i 阶后，还需要支付当前台阶的 cost
            dp[i] += costs[i - 1];
        }
        // 返回到达第 n 阶的最小总代价
        return dp[n];
    }
};