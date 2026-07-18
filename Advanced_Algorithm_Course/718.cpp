// https://leetcode.cn/problems/maximum-length-of-repeated-subarray/


class Solution
{
public:
    // 计算 nums1 和 nums2 中最长重复子数组的长度
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        // m 表示 nums1 的长度
        int m = nums1.size();
        // n 表示 nums2 的长度
        int n = nums2.size();
        // dp[i][j] 表示以 nums1[i-1] 和 nums2[j-1] 结尾的最长公共连续子数组长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // ret 用来记录全局最长重复子数组长度
        int ret = 0;
        // 枚举 nums1 的前 i 个元素
        for (int i = 1; i <= m; i++)
        {
            // 枚举 nums2 的前 j 个元素
            for (int j = 1; j <= n; j++)
            {
                // 如果当前两个元素相等，说明可以接在前面的公共连续子数组后面
                if (nums1[i - 1] == nums2[j - 1])
                    // 当前连续长度 = 前一个位置的连续长度 + 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                // 更新最长重复子数组长度
                ret = max(ret, dp[i][j]);
            }
        }
        // 返回最长重复子数组长度
        return ret;
    }
};