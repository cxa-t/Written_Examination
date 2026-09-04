// https://leetcode.cn/problems/guess-number-higher-or-lower-ii/

class Solution
{
public:
    vector<vector<int>> memo;                         // 记录每个区间猜中数字所需的最小保证金额
    int getMoneyAmount(int n)                         // 计算猜中1到n之间数字所需的最小保证金额
    {
        memo.resize(n + 1, vector<int>(n + 1));      // 初始化区间记忆数组
        return dfs(1, n);                            // 从完整区间1到n开始递归计算
    }
    int dfs(int left, int right)                     // 计算区间[left,right]内保证猜中的最小金额
    {
        if (left >= right) return 0;                  // 区间只剩一个或没有数字时无需再付钱
        if (memo[left][right]) return memo[left][right]; // 当前区间已计算则直接返回缓存结果
        int ret = INT_MAX;                           // 初始化当前区间的最小花费为最大值
        for (int head = left; head <= right; head++)  // 枚举当前第一次猜测的数字
        {
            int x = dfs(left, head - 1);             // 计算猜小后左区间的最小保证金额
            int y = dfs(head + 1, right);            // 计算猜大后右区间的最小保证金额
            ret = min(ret, head + max(x, y));        // 取最坏分支花费后再选择其中最小方案
        }
        memo[left][right] = ret;                     // 缓存当前区间的最优结果
        return memo[left][right];                    // 返回当前区间的最小保证金额
    }
};