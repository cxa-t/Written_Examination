// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/


class Solution
{
public:
    // ret 用来累加所有子集异或值的总和
    int ret = 0;
    // path 表示当前子集的异或值
    int path = 0;
    // dfs 表示从 nums[pos] 开始继续选择元素
    void dfs(vector<int>& nums, int pos)
    {
        // 当前 path 就代表一个子集的异或值，加入总和
        ret += path;
        // 从 pos 开始枚举后面可以选择的元素
        for (int i = pos; i < nums.size(); i++)
        {
            // 选择 nums[i]，将它加入当前子集的异或结果中
            path ^= nums[i];
            // 继续从 i + 1 开始选择后面的元素
            dfs(nums, i + 1);
            // 回溯：撤销 nums[i] 对当前异或结果的影响
            path ^= nums[i];
        }
    }

    // 计算所有子集异或值的总和
    int subsetXORSum(vector<int>& nums)
    {
        // 从第 0 个位置开始搜索所有子集
        dfs(nums, 0);
        // 返回所有子集异或值的总和
        return ret;
    }
};