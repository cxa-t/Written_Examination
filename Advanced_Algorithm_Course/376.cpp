// https://leetcode.cn/problems/wiggle-subsequence/

// 动态规划
class Solution
{
public:
    // 计算最长摆动子序列的长度
    int wiggleMaxLength(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // f[i] 表示以 nums[i] 结尾，并且最后一次差值为正数的最长摆动子序列长度
        vector<int> f(n, 1);
        // g[i] 表示以 nums[i] 结尾，并且最后一次差值为负数的最长摆动子序列长度
        vector<int> g(n, 1);
        // ret 用来记录全局最长摆动子序列长度
        int ret = 1;
        // 从第 1 个元素开始枚举结尾位置
        for (int i = 1; i < n; i++)
        {
            // 枚举 nums[i] 前面的所有元素 nums[j]
            for (int j = 0; j < i; j++)
            {
                // 如果 nums[i] > nums[j]，说明当前差值为正，要接在负差值状态后面
                if (nums[i] > nums[j])
                    f[i] = max(f[i], g[j] + 1);
                // 如果 nums[i] < nums[j]，说明当前差值为负，要接在正差值状态后面
                else if (nums[i] < nums[j])
                    g[i] = max(g[i], f[j] + 1);
            }
            // 更新全局最长摆动子序列长度
            ret = max(ret, max(f[i], g[i]));
        }
        // 返回最长摆动子序列长度
        return ret;
    }
};


// 贪心
class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int n = nums.size(); // 获取数组长度
        if (n < 2) return n; // 只有0个或1个元素时，直接返回
        int ret = 0; // 记录有效差值的个数
        int left = 0; // 上一个非零差值，初始化为0
        for (int i = 0; i < n - 1; i++) // 从第一个相邻差值开始遍历
        {
            int right = nums[i + 1] - nums[i]; // 计算当前相邻元素的差值
            if (right == 0) continue; // 当前两个元素相等，跳过
            if ((right > 0 && left <= 0) || (right < 0 && left >= 0)) ret++; // 首次出现非零差值或方向改变，有效差值数量加1
            left = right; // 更新上一个非零差值
        }
        return ret + 1; // 有效差值的个数加上初始的一个元素
    }
};