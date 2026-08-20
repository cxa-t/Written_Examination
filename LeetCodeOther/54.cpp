// https://leetcode.cn/problems/spiral-matrix/?envType=study-plan-v2&envId=top-100-liked


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        // 空矩阵直接返回空数组，避免读取 matrix[0] 发生越界异常
        if (matrix.empty() || matrix[0].empty()) 
            return {};
        // m 为矩阵的总行数，n 为矩阵的总列数
        int m = matrix.size(), n = matrix[0].size();
        // res 存放按螺旋顺序提取的所有元素
        vector<int> res;
        // 预分配内存空间，提升 push_back 的性能并减少内存重新分配
        res.reserve(m * n);
        // 计算可以构成完整“封闭矩形环”的圈数（由长宽较小的一方决定）
        int layers = min(m, n) / 2;
        // 循环遍历每一个完整的外圈，k 代表当前圈的层级索引（从 0 开始）
        for (int k = 0; k < layers; ++k) 
        {
            // 遍历上边：从左向右读取，区间 [k, n - k - 1)，留出右上角点给右边遍历
            for (int j = k; j < n - k - 1; ++j) 
                res.push_back(matrix[k][j]);
            // 遍历右边：从上向下读取，区间 [k, m - k - 1)，留出右下角点给下边遍历
            for (int i = k; i < m - k - 1; ++i) 
                res.push_back(matrix[i][n - k - 1]);
            // 遍历下边：从右向左读取，区间 (k, n - k - 1]，留出左下角点给左边遍历
            for (int j = n - k - 1; j > k; --j) 
                res.push_back(matrix[m - k - 1][j]);
            // 遍历左边：从下向上读取，区间 (k, m - k - 1]，留出左上角点给下一圈使用
            for (int i = m - k - 1; i > k; --i) 
                res.push_back(matrix[i][k]);
        }
        // 当较短的边为奇数时，外圈剥离完成后内部必然存在剩余的单行或单列
        if (min(m, n) % 2 != 0) 
        {
            // k 为未被外圈覆盖的中心残余区域起点索引
            int k = layers;
            // 若行数小于等于列数，说明剥离外圈后剩余的是单行（或正方形中心单个点）
            if (m <= n) 
            {
                // 遍历剩余的单行，从左到右闭区间 [k, n - k - 1] 全部压入结果
                for (int j = k; j <= n - k - 1; ++j) 
                    res.push_back(matrix[k][j]);
            }
            else 
            {
                // 若行数大于列数，说明剥离外圈后剩余的是单列
                // 遍历剩余的单列，从上到下闭区间 [k, m - k - 1] 全部压入结果
                for (int i = k; i <= m - k - 1; ++i) 
                    res.push_back(matrix[i][n - k - 1]);
            }
        }
        // 返回按螺旋次序收集好的所有元素数组
        return res;
    }
};