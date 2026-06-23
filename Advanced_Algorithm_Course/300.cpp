// https://leetcode.cn/problems/longest-increasing-subsequence/


class Solution
{
public:
    // 计算最长递增子序列的长度
    int lengthOfLIS(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // dp[i] 表示以 nums[i] 结尾的最长递增子序列长度
        vector<int> dp(n, 1);
        // ret 用来记录全局最长递增子序列长度
        int ret = 1;
        // 从第 1 个元素开始遍历
        for (int i = 1; i < n; i++)
        {
            // maxdp 用来记录 nums[i] 前面可以接上的最大 dp[j]
            int maxdp = 0;
            // 枚举 nums[i] 前面的所有元素
            for (int j = 0; j < i; j++)
            {
                // 只有 nums[j] 小于 nums[i]，才能把 nums[i] 接在 nums[j] 后面
                if (nums[j] < nums[i])
                    // 更新可以接到 nums[i] 前面的最长递增子序列长度
                    maxdp = max(maxdp, dp[j]);
            }
            // 以 nums[i] 结尾的最长递增子序列长度 = 前面最大长度 + 当前元素
            dp[i] = maxdp + 1;
            // 更新全局最长递增子序列长度
            ret = max(dp[i], ret);
        }
        // 返回最长递增子序列长度
        return ret;
    }
};