// https://leetcode.cn/problems/flood-fill/

class Solution
{
public:
    int m;                                             // 保存图像的行数
    int n;                                             // 保存图像的列数

    int dx[4] = { -1,1,0,0 };                              // 定义上下左右四个方向的行偏移
    int dy[4] = { 0,0,-1,1 };                              // 定义上下左右四个方向的列偏移

    void dfs(vector<vector<int>>& image, int i, int j, int prev, int color) // 从当前位置递归填充颜色
    {
        if (image[i][j] != prev)                          // 当前格子不是原始颜色则停止搜索
            return;                                    // 结束当前递归分支

        image[i][j] = color;                             // 将当前格子修改为目标颜色

        for (int k = 0; k < 4; k++)                           // 遍历四个相邻方向
        {
            int x = i + dx[k];                         // 计算相邻位置的行坐标
            int y = j + dy[k];                         // 计算相邻位置的列坐标

            if (x >= 0 && x < m && y >= 0 && y < n)      // 判断相邻位置是否在图像范围内
            {
                dfs(image, x, y, prev, color);         // 继续递归处理相邻区域
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) // 执行图像填充操作
    {
        m = image.size();                                // 获取图像行数
        n = image[0].size();                             // 获取图像列数
        if (image[sr][sc] == color)                       // 原颜色和目标颜色相同无需处理
            return image;                              // 直接返回原图像
        dfs(image, sr, sc, image[sr][sc], color);           // 从起始位置开始深度优先填充
        return image;                                  // 返回填充后的图像
    }
};