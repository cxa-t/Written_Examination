// https://leetcode.cn/problems/matrix-block-sum/

class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int m = mat.size();//行
        int n = mat[0].size();//列
        vector<vector<int>> ret(m, vector<int>(n, 0));
        //前缀和数组
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        //ret数组
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //映射为dp数组的下标
                int x1 = 1 + max(0, i - k);
                int y1 = 1 + max(0, j - k);
                int x2 = 1 + min(m - 1, i + k);
                int y2 = 1 + min(n - 1, j + k);
                //依据dp数组进行计算二维前缀和
                ret[i][j] = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
            }
        }
        return ret;
    }
};