// https://leetcode.cn/problems/target-sum/


class Solution
{
public:
    int target = 0;                              // 保存目标和
    int ret = 0;                                 // 保存满足目标和的方案数量

    void dfs(vector<int>& nums, int pos, int path) // pos表示当前处理的位置，path表示当前计算结果
    {
        if (pos == nums.size())                   // 所有数字都已经添加正号或负号
        {
            if (path == target)                   // 当前计算结果等于目标值
                ret++;                           // 满足条件的方案数加一
            return;                              // 当前递归分支结束
        }

        dfs(nums, pos + 1, path + nums[pos]);    // 当前数字选择正号并递归处理下一个数字
        dfs(nums, pos + 1, path - nums[pos]);    // 当前数字选择负号并递归处理下一个数字
    }

    int findTargetSumWays(vector<int>& nums, int _target)
    {
        target = _target;                        // 保存题目给定的目标值
        dfs(nums, 0, 0);                         // 从第0个数字开始且初始和为0
        return ret;                              // 返回满足目标和的方案数量
    }
};