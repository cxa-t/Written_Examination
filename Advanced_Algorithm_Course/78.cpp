// https://leetcode.cn/problems/subsets/


class Solution
{
    // path 用来保存当前正在构造的子集
    vector<int> path;
    // ret 用来保存所有子集结果
    vector<vector<int>> ret;
public:
    // dfs 表示从 nums[i] 这个位置开始决定选不选
    void dfs(vector<int>& nums, int i)
    {
        // 如果 i 已经走到数组末尾，说明当前子集构造完成
        if (i == nums.size())
        {
            // 将当前子集加入结果集
            ret.push_back(path);
            // 当前递归结束，返回上一层
            return;
        }
        // 选择 nums[i] 加入当前子集
        path.push_back(nums[i]);
        // 继续处理下一个位置
        dfs(nums, i + 1);
        // 回溯：撤销刚才选择的 nums[i]
        path.pop_back();

        // 不选择 nums[i]，直接继续处理下一个位置
        dfs(nums, i + 1);
    }

    // 返回 nums 的所有子集
    vector<vector<int>> subsets(vector<int>& nums)
    {
        // 从第 0 个位置开始进行选择
        dfs(nums, 0);
        // 返回所有子集
        return ret;
    }
};