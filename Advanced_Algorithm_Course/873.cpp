// https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/


class Solution
{
public:
    // 计算数组中最长斐波那契式子序列的长度
    int lenLongestFibSubseq(vector<int>& arr)
    {
        // n 表示数组长度
        int n = arr.size();
        // hash 用来记录每个数字对应的下标
        unordered_map<int, int> hash;
        // dp[i][j] 表示以 arr[i]、arr[j] 作为最后两个数的最长斐波那契式子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 2));
        // 将每个数字和它的下标存入哈希表，方便快速查找
        for (int i = 0; i < n; i++) hash[arr[i]] = i;
        // ret 用来记录最长斐波那契式子序列长度
        int ret = 0;
        // 枚举斐波那契式子序列的最后一个数 arr[j]
        for (int j = 2; j < n; j++)
        {
            // 枚举斐波那契式子序列的倒数第二个数 arr[i]
            for (int i = 1; i < j; i++)
            {
                // 如果存在前一个数 arr[j] - arr[i]，并且它小于 arr[i]，说明能组成递增的斐波那契式序列
                if (hash.count(arr[j] - arr[i]) && arr[j] - arr[i] < arr[i])
                {
                    // 用前一个状态更新当前以 arr[i]、arr[j] 结尾的最长长度
                    dp[i][j] = dp[hash[arr[j] - arr[i]]][i] + 1;
                }
                // 更新全局最长长度
                ret = max(ret, dp[i][j]);
            }
        }
        // 如果最长长度小于 3，说明不存在合法斐波那契式子序列
        return ret < 3 ? 0 : ret;
    }
};