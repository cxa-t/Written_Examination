//  https://leetcode.cn/problems/set-matrix-zeroes/?envType=study-plan-v2&envId=top-100-liked


class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size(); // 获取矩阵的行数
        int n = matrix[0].size(); // 获取矩阵的列数
        bool firstRow = false; // 记录第一行原本是否存在0
        bool firstCol = false; // 记录第一列原本是否存在0
        for(int j = 0; j < n; j++) // 遍历第一行，判断第一行是否存在0
        {
            if(matrix[0][j] == 0) // 如果第一行的某个元素为0
            {
                firstRow = true; // 标记第一行需要全部变成0
                break; // 已经找到0，不需要继续查找
            }
        }
        for(int i = 0; i < m; i++) // 遍历第一列，判断第一列是否存在0
        {
            if(matrix[i][0] == 0) // 如果第一列的某个元素为0
            {
                firstCol = true; // 标记第一列需要全部变成0
                break; // 已经找到0，不需要继续查找
            }
        }
        for(int i = 1; i < m; i++) // 从第二行开始遍历，暂时不处理第一行
        {
            for(int j = 1; j < n; j++) // 从第二列开始遍历，暂时不处理第一列
            {
                if(matrix[i][j] == 0) // 如果当前位置的元素为0，说明它所在的行和列都需要变成0
                {
                    matrix[i][0] = 0; // 将当前行的第一个元素设为0，标记这一行需要全部变成0
                    matrix[0][j] = 0; // 将当前列的第一个元素设为0，标记这一列需要全部变成0
                }
            }
        }
        for(int i = 1; i < m; i++) // 从第二行开始，根据第一行和第一列中的标记修改矩阵
        {
            for(int j = 1; j < n; j++) // 从第二列开始，判断当前位置是否需要变成0
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) // 如果当前行或当前列被标记为0，说明当前位置需要变成0
                {
                    matrix[i][j] = 0; // 将当前位置的元素修改为0
                }
            }
        }
        if(firstRow == true) // 如果第一行原本存在0，就需要将第一行全部变成0
        {
            for(int j = 0; j < n; j++) // 遍历第一行的所有元素
            {
                matrix[0][j] = 0; // 将第一行的每个元素都修改为0
            }
        }
        if(firstCol == true) // 如果第一列原本存在0，就需要将第一列全部变成0
        {
            for(int i = 0; i < m; i++) // 遍历第一列的所有元素
            {
                matrix[i][0] = 0; // 将第一列的每个元素都修改为0
            }
        }
    }
};