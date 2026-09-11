// https://leetcode.cn/problems/target-sum/

// dfs
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

//01背包
class Solution  
{ 
public: 
    int findTargetSumWays(vector<int>& nums, int target)              // 计算添加正负号后结果等于target的方案数量
    { 
        int sum = 0;                                                   // 保存数组所有元素的总和
        for(int e : nums) sum += e;                                    // 累加得到所有数字的总和
        int goal = (target + sum) / 2;                                 // 将目标和问题转化为子集和为goal的问题
        if(goal < 0 || (target + sum) % 2) return 0;                    // goal小于0或无法整除时说明不存在合法方案
        vector<vector<int>> dp(nums.size() + 1, vector<int>(goal + 1)); // dp[i][j]表示前i个数凑出和j的方案数量
        dp[0][0] = 1;                                                  // 不选择任何数字凑出0有一种方案
        for(int i = 1; i <= nums.size(); i++)                          // 依次考虑数组中的每一个数字
        { 
            for(int j = 0; j <= goal; j++)                             // 枚举当前需要凑出的目标和
            { 
                dp[i][j] = dp[i-1][j];                                 // 不选择当前数字时继承上一层方案数
                if(j >= nums[i-1])                                     // 当前目标和能够选择当前数字
                    dp[i][j] += dp[i-1][j-nums[i-1]];                  // 加上选择当前数字后的方案数量
            } 
        }  
        return dp[nums.size()][goal];                                  // 返回所有数字凑出goal的方案数量
    } 
};

// 空间优化
class Solution  
{ 
public: 
    int findTargetSumWays(vector<int>& nums, int target)              // 计算添加正负号后结果等于target的方案数量
    { 
        int sum = 0;                                                   // 保存数组所有元素的总和
        for(int e : nums) sum += e;                                    // 累加得到所有数字的总和
        int goal = (target + sum) / 2;                                 // 将目标和问题转化为子集和为goal的问题
        if(goal < 0 || (target + sum) % 2) return 0;                    // goal小于0或无法整除时说明不存在合法方案
        vector<int> dp(goal + 1);                                      // dp[j]表示当前能够凑出和j的方案数量
        dp[0] = 1;                                                      // 凑出和0初始有一种方案
        for(int i = 1; i <= nums.size(); i++)                          // 依次考虑数组中的每一个数字
        { 
            for(int j = goal; j >= 0; j--)                             // 倒序枚举背包容量避免当前数字被重复使用
            { 
                if(j >= nums[i-1])                                     // 当前容量能够选择第i个数字
                    dp[j] += dp[j-nums[i-1]];                          // 加上选择当前数字后对应的方案数量
            } 
        }  
        return dp[goal];                                                // 返回凑出goal的所有方案数量
    } 
};
