// https://leetcode.cn/problems/number-of-longest-increasing-subsequence/


class Solution
{
public:
    // 计算最长递增子序列的个数
    int findNumberOfLIS(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // len[i] 表示以 nums[i] 结尾的最长递增子序列长度
        vector<int> len(n, 1);
        // count[i] 表示以 nums[i] 结尾，并且长度为 len[i] 的递增子序列个数
        vector<int> count(n, 1);
        // retlen 表示当前全局最长递增子序列长度
        int retlen = 1;
        // retcount 表示当前全局最长递增子序列的个数
        int retcount = 1;
        // 从第 1 个元素开始枚举结尾位置
        for (int i = 1; i < n; i++)
        {
            // 枚举 nums[i] 前面的所有元素
            for (int j = 0; j < i; j++)
            {
                // 只有 nums[j] 小于 nums[i]，才能把 nums[i] 接到 nums[j] 后面
                if (nums[i] > nums[j])
                {
                    // 如果从 j 接到 i 后，长度刚好等于当前 len[i]，说明找到另一种方案
                    if (len[j] + 1 == len[i]) count[i] += count[j];
                    // 如果从 j 接到 i 后，长度超过当前 len[i]，说明找到更长方案
                    else if (len[j] + 1 > len[i])
                    {
                        // 更新以 nums[i] 结尾的最长递增子序列长度
                        len[i] = len[j] + 1;
                        // 方案数重置为 count[j]
                        count[i] = count[j];
                    }
                }
            }
            // 如果当前 len[i] 等于全局最长长度，就把当前方案数累加进去
            if (retlen == len[i]) retcount += count[i];
            // 如果当前 len[i] 超过全局最长长度，就更新全局长度和方案数
            else if (retlen < len[i])
            {
                // 更新全局最长递增子序列长度
                retlen = len[i];
                // 重置全局方案数为当前 count[i]
                retcount = count[i];
            }
        }
        // 返回最长递增子序列的总个数
        return retcount;
    }
};