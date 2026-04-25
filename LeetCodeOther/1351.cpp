// https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        // 4 3  2 -1
        // 3 2  1 -1
        // 1 1  -1 -2
        //-1 -1 -2 -3
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = n - 1;
        int ret = 0;
        while (i < m && j >= 0)
        {
            if (grid[i][j] < 0)
            {
                ret += m - i;//说明这一列都是负数，总共有当前行数这么多
                j--;//将当前列排除在外
            }
            else if (grid[i][j] >= 0)
            {
                i++;//说明当前行全部是正整数，直接跳到下一行即可
            }
        }
        return ret;
    }
};