// https://leetcode.cn/problems/ones-and-zeroes/

// 优化前
class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)                       // 在最多使用m个0和n个1的条件下求最大字符串数量
    {
        int len = strs.size();                                                // 获取字符串数组的长度
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1))); // dp[i][j][k]表示前i个字符串使用不超过j个0和k个1时的最大数量
        for (int i = 1; i <= len; i++)                                         // 依次考虑每一个字符串
        {
            int sum_1 = 0;                                                    // 统计当前字符串中1的数量
            int sum_0 = 0;                                                    // 统计当前字符串中0的数量
            for (auto e : strs[i - 1])                                         // 遍历当前字符串的每一个字符
            {
                if (e == '0') sum_0++;                                         // 当前字符为0则0的数量加一
                else sum_1++;                                                 // 当前字符为1则1的数量加一
            }
            for (int j = 0; j <= m; j++)                                       // 枚举当前可以使用的0的数量
            {
                for (int k = 0; k <= n; k++)                                   // 枚举当前可以使用的1的数量
                {
                    dp[i][j][k] = dp[i - 1][j][k];                            // 不选择当前字符串时继承上一层结果
                    if (j >= sum_0 && k >= sum_1)                              // 当前0和1的容量能够放下这个字符串
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - sum_0][k - sum_1] + 1); // 比较选择和不选择当前字符串的最大数量
                    }
                }
            }
        }
        return dp[len][m][n];                                                 // 返回满足0和1限制下能够选择的最大字符串数量
    }
};


// 优化后
class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)              // 在最多使用m个0和n个1的条件下求最大字符串数量
    {
        int len = strs.size();                                       // 获取字符串数组的长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));           // dp[j][k]表示使用不超过j个0和k个1时的最大字符串数量
        for (int i = 1; i <= len; i++)                                // 依次考虑每一个字符串
        {
            int sum_1 = 0;                                           // 统计当前字符串中1的数量
            int sum_0 = 0;                                           // 统计当前字符串中0的数量
            for (auto e : strs[i - 1])                                // 遍历当前字符串中的所有字符
            {
                if (e == '0') sum_0++;                                // 当前字符为0则0的数量加一
                else sum_1++;                                        // 当前字符为1则1的数量加一
            }
            for (int j = m; j >= sum_0; j--)                          // 倒序枚举可使用的0的数量避免重复选择当前字符串
                for (int k = n; k >= sum_1; k--)                      // 倒序枚举可使用的1的数量避免重复选择当前字符串
                    dp[j][k] = max(dp[j][k], dp[j - sum_0][k - sum_1] + 1); // 比较选择和不选择当前字符串的最大数量
        }
        return dp[m][n];                                             // 返回满足0和1限制下可选择的最大字符串数量
    }
};