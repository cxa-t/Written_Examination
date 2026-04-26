// https://leetcode.cn/problems/flip-square-submatrix-vertically/

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> ret(grid);
        int upr = x;
        int downr = upr + k - 1;
        int limitl = y + k - 1;
        while (upr < downr)
        {
            int downl = y;
            int upl = y;
            while (downl <= limitl)
            {
                std::swap(ret[upr][upl++], ret[downr][downl++]);
            }
            upr++;
            downr--;
        }
        return ret;
    }
};