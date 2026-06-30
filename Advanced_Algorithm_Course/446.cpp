// https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/


class Solution
{
public:
    // 计算数组中等差子序列的个数，长度至少为 3
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // 如果数组长度小于 3，不可能形成长度至少为 3 的等差子序列
        if (n < 3) return 0;
        // dp[i][j] 表示以 nums[i]、nums[j] 作为最后两个数的等差子序列个数
        vector<vector<int>> dp(n, vector<int>(n));
        // hash[value] 存放这个 value 在 nums 中出现过的所有下标
        unordered_map<long long int, vector<int>> hash;
        // 遍历数组，把每个数字出现的位置存入哈希表
        for (int i = 0; i < n; i++)
            // 将 nums[i] 的下标 i 放入对应数字的下标数组中
            hash[nums[i]].push_back(i);
        // ret 用来记录所有等差子序列的总数量
        int ret = 0;
        // 枚举等差子序列的最后一个位置 j
        for (int j = 2; j < n; j++)
        {
            // 枚举等差子序列的倒数第二个位置 i
            for (int i = 1; i < j; i++)
            {
                // 如果 nums[k]、nums[i]、nums[j] 构成等差，则 nums[k] = 2 * nums[i] - nums[j]
                long long int a = (long long int)2 * nums[i] - nums[j];
                // 如果数组中存在值为 a 的元素，说明可能找到前一个位置 k
                if (hash.count(a))
                {
                    // 遍历所有值为 a 的位置
                    for (int k = 0; k < hash[a].size(); k++)
                    {
                        // 只有位置在 i 左边，才能作为 nums[i] 前面的元素
                        if (hash[a][k] < i)
                            // 新增数量 = 以前 k,i 结尾的序列数量 + nums[k],nums[i],nums[j] 这一个新三元组
                            dp[i][j] += dp[hash[a][k]][i] + 1;
                        // 因为下标是递增存入的，遇到不小于 i 的位置就可以停止
                        else break;
                    }
                }
                // 把以 nums[i]、nums[j] 结尾的等差子序列数量加入答案
                ret += dp[i][j];
            }
        }
        // 返回所有长度至少为 3 的等差子序列数量
        return ret;
    }
};