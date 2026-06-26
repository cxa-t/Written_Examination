// https://leetcode.cn/problems/maximum-length-of-pair-chain/


class Solution {
public:
    // 计算最长数对链的长度
    int findLongestChain(vector<vector<int>>& pairs)
    {
        // 先按照数对的第一个元素进行排序
        sort(pairs.begin(), pairs.end());
        // n 表示数对的数量
        int n = pairs.size();
        // dp[i] 表示以 pairs[i] 结尾的最长数对链长度
        vector<int> dp(n, 1);
        // ret 用来记录全局最长数对链长度
        int ret = 1;
        // 从第 1 个数对开始枚举结尾位置
        for (int i = 1; i < n; i++)
        {
            // 枚举 pairs[i] 前面的所有数对
            for (int j = 0; j < i; j++)
            {
                // 如果 pairs[j] 的右端点小于 pairs[i] 的左端点，说明可以连接
                if (pairs[i][0] > pairs[j][1])
                {
                    // 用 pairs[j] 接到 pairs[i] 前面，更新以 i 结尾的最长链长度
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
            // 更新全局最长数对链长度
            ret = max(ret, dp[i]);
        }
        // 返回最长数对链长度
        return ret;
    }
};