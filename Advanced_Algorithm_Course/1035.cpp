// https://leetcode.cn/problems/uncrossed-lines/


class Solution
{
public:
    // 计算 nums1 和 nums2 之间最多可以画多少条不相交的连线
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        // m 表示 nums1 的长度
        int m = nums1.size();
        // n 表示 nums2 的长度
        int n = nums2.size();
        // dp[i][j] 表示 nums1 前 i 个元素和 nums2 前 j 个元素的最大不相交连线数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 枚举 nums1 的前 i 个元素
        for (int i = 1; i <= m; i++)
        {
            // 枚举 nums2 的前 j 个元素
            for (int j = 1; j <= n; j++)
            {
                // 如果当前两个元素相等，就可以连一条线
                if (nums1[i - 1] == nums2[j - 1])
                    // 当前连线数 = 前面部分的最大连线数 + 当前这一条线
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                // 如果当前两个元素不相等，就不能直接连线
                else
                    // 分别尝试去掉 nums1 当前元素或 nums2 当前元素，取最大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // 返回两个完整数组之间的最大不相交连线数
        return dp[m][n];
    }
};