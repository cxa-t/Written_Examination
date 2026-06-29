// https://leetcode.cn/problems/longest-arithmetic-subsequence/


class Solution
{
public:
    // 计算最长等差子序列的长度
    int longestArithSeqLength(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // hash 用来保存当前 i 左边已经出现过的数字及其下标
        unordered_map<int, int> hash;
        // dp[i][j] 表示以 nums[i] 和 nums[j] 作为最后两个数的最长等差子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 2));
        // ret 用来记录全局最长等差子序列长度，至少两个数可以形成长度为 2 的序列
        int ret = 2;
        // 先把第 0 个数字放入哈希表，供后续查找
        hash[nums[0]] = 0;
        // 枚举等差子序列的中间位置 i
        for (int i = 1; i < n; i++)
        {
            // 枚举等差子序列的右端位置 j
            for (int j = i + 1; j < n; j++)
            {
                // 如果 nums[k], nums[i], nums[j] 构成等差，则 nums[k] = 2 * nums[i] - nums[j]
                int a = 2 * nums[i] - nums[j];
                // 如果 i 左边存在值为 a 的数字，说明可以组成等差序列
                if (hash.count(a))
                {
                    // 用 dp[k][i] 推出 dp[i][j]，其中 k 是值为 a 的位置
                    dp[i][j] = dp[hash[a]][i] + 1;
                }
                // 更新最长等差子序列长度
                ret = max(ret, dp[i][j]);
            }
            // 当前 i 处理完后，把 nums[i] 放入哈希表，供后面的 i 使用
            hash[nums[i]] = i;
        }
        // 返回最长等差子序列长度
        return ret;
    }
};