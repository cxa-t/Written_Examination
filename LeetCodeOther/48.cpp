// https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-100-liked


class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();                                      // 获取矩阵的边长
        for (int i = 0; i < n / 2; i++)                             // 遍历矩阵上半部分的行
        {
            for (int j = 0; j < (n + 1) / 2; j++)                   // 遍历矩阵左半部分的列
            {
                int tmp = matrix[i][j];                             // 暂存当前左上角元素
                matrix[i][j] = matrix[n - 1 - j][i];                // 将左下角元素移动到左上角
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]; // 将右下角元素移动到左下角
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]; // 将右上角元素移动到右下角
                matrix[j][n - 1 - i] = tmp;                         // 将原左上角元素移动到右上角
            }
        }
    }
};