// https://leetcode.cn/problems/unique-binary-search-trees/


class Solution
{
public:
    int numTrees(int n)                               // 计算由1到n组成的不同二叉搜索树数量
    {
        vector<int> dp(n + 1);                        // dp[i]表示i个节点能够组成的不同二叉搜索树数量
        dp[0] = 1;                                    // 空树只有一种结构
        for (int i = 1; i <= n; i++)                   // 依次计算1到n个节点时的结果
        {
            for (int j = 1; j <= i; j++)               // 枚举第j个节点作为当前二叉搜索树的根节点
            {
                dp[i] += dp[j - 1] * dp[i - j];           // 左子树方案数乘右子树方案数并累加到当前结果
            }
        }
        return dp[n];                                  // 返回n个节点能够组成的不同二叉搜索树数量
    }
};