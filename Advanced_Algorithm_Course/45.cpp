// https://leetcode.cn/problems/jump-game-ii/

class Solution // 动态规划解法
{
public: // 公有成员区域
    int jump(vector<int>& nums) // 返回从下标0跳到最后一个位置所需要的最少跳跃次数
    {
        int n = nums.size(); // 获取数组长度
        vector<int> dp(n, 0x3f3f3f3f); // dp[i]表示跳到下标i所需要的最少跳跃次数，初始设为一个很大的值
        dp[0] = 0; // 起点就是下标0，因此到达下标0不需要跳跃
        for (int i = 1; i < n; i++) // 从下标1开始，依次计算到达每个位置所需要的最少跳跃次数
        {
            for (int j = 0; j < i; j++) // 枚举当前位置i之前的所有位置j，判断能否从j直接跳到i
            {
                if (nums[j] + j >= i) // 如果j位置能够到达的最远位置不小于i，说明可以从j直接跳到i
                    dp[i] = min(dp[j] + 1, dp[i]); // 从j跳到i需要在dp[j]基础上再跳一次，用较小值更新dp[i]
            }
        }
        return dp[n - 1]; // 返回到达最后一个位置所需要的最少跳跃次数
    }
};


class Solution // 贪心加区间搜索解法
{
public: // 公有成员区域
    int jump(vector<int>& nums) // 返回从下标0跳到最后一个位置所需要的最少跳跃次数
    {
        int n = nums.size(); // 获取数组长度
        int left = 0; // 当前这一跳能够到达区间的左边界
        int right = 0; // 当前这一跳能够到达区间的右边界，初始只能到达下标0
        int ret = 0; // 记录当前已经进行的跳跃次数
        int maxPos = 0; // 记录从当前区间中的所有位置出发，下一跳最远能够到达的位置
        while (left <= right) // 只要当前能够到达的区间仍然有效，就继续向后寻找
        {
            if (maxPos >= n - 1) return ret; // 如果当前已经能够到达最后一个位置，直接返回已经使用的跳跃次数
            for (int i = left; i <= right; i++) // 遍历当前这一跳能够到达的所有位置
            {
                maxPos = max(maxPos, nums[i] + i); // 计算从当前区间中任意位置再跳一次后，最远能够到达的位置
            }
            left = right + 1; // 下一层能够到达区间的左边界，是当前区间右边界的下一个位置
            right = maxPos; // 下一层能够到达区间的右边界，就是刚刚计算出的最远位置
            ret++; // 从当前区间继续向后扩展了一层，表示又进行了一次跳跃
        }
        return -1; // 如果无法到达最后一个位置则返回-1，不过题目通常保证一定可以到达最后一个位置
    }
};