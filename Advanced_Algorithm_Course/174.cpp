// https://leetcode.cn/problems/dungeon-game/


//也就是从终点反推：
//当前位置只能往右边或下边走，所以先选择后续所需生命值更小的方向，再减去当前格子对血量的影响。
//如果算出来小于 1，说明至少也要保持 1 点生命值才能活着。
class Solution
{
public:
    // 计算骑士进入地牢前至少需要的初始生命值
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        // m 表示地牢的行数
        int m = dungeon.size();
        // n 表示地牢的列数
        int n = dungeon[0].size();
        // dp[i][j] 表示从位置 i,j 出发，到达终点所需的最低生命值
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        // 初始化终点右边和下边的虚拟位置为 1，方便统一递推
        dp[m][n - 1] = dp[m - 1][n] = 1;
        // 从最后一行向第一行倒着遍历
        for (int i = m - 1; i >= 0; i--)
        {
            // 从最后一列向第一列倒着遍历
            for (int j = n - 1; j >= 0; j--)
            {
                // 当前所需生命值 = 右边或下边较小需求 - 当前格子的血量影响
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
                // 生命值最低必须是 1，不能小于等于 0
                dp[i][j] = max(1, dp[i][j]);
            }
        }
        // 返回从左上角出发所需的最低初始生命值
        return dp[0][0];
    }
};