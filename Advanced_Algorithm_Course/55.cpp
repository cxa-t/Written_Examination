// https://leetcode.cn/problems/jump-game/


class Solution // 定义题解类
{
public: // 公有成员区域
    bool canJump(vector<int>& nums) // 判断是否能够从数组下标0出发，最终到达最后一个下标
    {
        int left = 0, right = 0, maxpos = 0, n = nums.size(); // left 和 right 表示当前能够到达的区间范围，maxpos 表示从当前区间再跳一步最远能到达的位置，n 表示数组长度
        while (left <= right) // 只要当前可到达区间仍然有效，就继续向后扩展能够到达的范围
        {
            if (right >= n - 1) return true; // 如果当前能够到达的最右位置已经到达或超过最后一个下标，说明一定可以到达终点，直接返回true
            for (int i = left; i <= right; i++) // 遍历当前这一层所有能够到达的位置，寻找下一步能够到达的最远位置
            {
                maxpos = max(maxpos, nums[i] + i); // nums[i]表示从位置i最多能跳多少步，因此i+nums[i]就是从当前位置最远能到达的下标，用它更新maxpos
            }
            left = right + 1; // 下一轮搜索的左边界设置为当前区间右边界的下一个位置，避免重复遍历之前已经处理过的位置
            right = maxpos; // 将下一轮搜索的右边界更新为当前所有位置能够扩展到的最远位置
        }
        return false; // 如果最终出现left大于right，说明可到达范围无法继续向后扩展，并且还没有到达终点，因此返回false
    }
};