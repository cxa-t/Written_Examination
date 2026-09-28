// https://leetcode.cn/problems/longest-increasing-subsequence/


class Solution
{
public:
    // 计算最长递增子序列的长度
    int lengthOfLIS(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // dp[i] 表示以 nums[i] 结尾的最长递增子序列长度
        vector<int> dp(n, 1);
        // ret 用来记录全局最长递增子序列长度
        int ret = 1;
        // 从第 1 个元素开始遍历
        for (int i = 1; i < n; i++)
        {
            // maxdp 用来记录 nums[i] 前面可以接上的最大 dp[j]
            int maxdp = 0;
            // 枚举 nums[i] 前面的所有元素
            for (int j = 0; j < i; j++)
            {
                // 只有 nums[j] 小于 nums[i]，才能把 nums[i] 接在 nums[j] 后面
                if (nums[j] < nums[i])
                    // 更新可以接到 nums[i] 前面的最长递增子序列长度
                    maxdp = max(maxdp, dp[j]);
            }
            // 以 nums[i] 结尾的最长递增子序列长度 = 前面最大长度 + 当前元素
            dp[i] = maxdp + 1;
            // 更新全局最长递增子序列长度
            ret = max(dp[i], ret);
        }
        // 返回最长递增子序列长度
        return ret;
    }
};


// 记忆化搜索
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)                     // 计算最长严格递增子序列的长度
    {
        int n = nums.size();                               // 获取数组长度
        vector<int> memo(n);                               // 记录以每个位置作为起点的最长递增子序列长度
        int ret = 0;                                       // 保存全局最长递增子序列长度
        for (int i = 0; i < n; i++)                         // 枚举每一个位置作为递增子序列起点
        {
            ret = max(ret, dfs(i, nums, memo));            // 更新所有起点中的最大递增子序列长度
        }
        return ret;                                        // 返回最长严格递增子序列长度
    }
    int dfs(int pos, vector<int>& nums, vector<int>& memo) // 计算以pos位置开头的最长递增子序列长度
    {
        if (memo[pos]) return memo[pos];                    // 当前状态已计算则直接返回缓存结果
        int ret = 1;                                       // 至少可以选择当前元素自身形成长度1的子序列
        for (int i = pos + 1; i < nums.size(); i++)         // 枚举当前元素之后的所有位置
        {
            if (nums[i] > nums[pos])                        // 判断后面的元素是否可以接在当前元素之后
            {
                ret = max(ret, dfs(i, nums, memo) + 1);    // 选择当前元素并更新最长递增子序列长度
            }
        }
        memo[pos] = ret;                                   // 缓存以pos为起点的最长递增子序列长度
        return memo[pos];                                  // 返回当前状态的计算结果
    }
};


// 贪心
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) // 返回最长严格递增子序列的长度
    {
        int n = nums.size(); // 获取数组长度
        vector<int> ret; // ret[i] 表示长度为 i+1 的递增子序列中，结尾元素的最小值
        ret.push_back(nums[0]); // 先把第一个元素加入 ret，表示当前最长递增子序列长度至少为1
        for (int i = 1; i < n; i++) // 从第二个元素开始依次遍历 nums
        {
            if (nums[i] > ret.back()) // 如果当前元素比 ret 最后一个元素还大，说明可以接在当前最长递增子序列后面
            {
                ret.push_back(nums[i]); // 将当前元素加入 ret，使当前最长递增子序列长度加1
            }
            else // 当前元素无法直接接在最长递增子序列后面，需要找到合适位置进行替换
            {
                int left = 0; // 二分查找左边界
                int right = ret.size() - 1; // 二分查找右边界
                while (left < right) // 当左右边界没有重合时继续二分查找
                {
                    int mid = (left + right) / 2; // 计算中间位置
                    if (ret[mid] < nums[i]) left = mid + 1; // 如果 ret[mid] 小于当前元素，说明替换位置一定在 mid 的右侧
                    else right = mid; // 如果 ret[mid] 大于等于当前元素，说明 mid 可能就是答案，因此缩小右边界
                }
                ret[left] = nums[i]; // 用当前元素替换第一个大于等于它的元素，使对应长度的递增子序列结尾尽可能小
            }
        }
        return ret.size(); // ret 的长度就是最长严格递增子序列的长度
    }
};