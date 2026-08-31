// https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/


class Solution
{
public:
    int ret = 0;                                      // 记录机器人能够到达的格子数量
    vector<vector<bool>> vis;                         // 标记每个格子是否已经访问
    int m = 0;                                        // 保存网格的行数
    int n = 0;                                        // 保存网格的列数
    int dx[2] = { 0, 1 };                               // 定义向右和向下两个方向的行偏移
    int dy[2] = { 1, 0 };                               // 定义向右和向下两个方向的列偏移
    int digit(int num)                                // 计算一个整数各位数字之和
    {
        int ret = 0;                                  // 保存当前数字的数位和
        while (num)                                    // 逐位处理当前整数
        {
            ret += num % 10;                          // 累加当前最低位数字
            num /= 10;                                // 删除当前最低位数字
        }
        return ret;                                   // 返回整数的数位和
    }
    void dfs(int i, int j, int cnt)                   // 从当前位置继续搜索所有可达格子
    {
        vis[i][j] = true;                             // 标记当前位置已经访问
        ret++;                                        // 可到达的格子数量加一
        for (int k = 0; k < 2; k++)                    // 枚举向右和向下两个移动方向
        {
            int x = i + dx[k];                        // 计算下一位置的行坐标
            int y = j + dy[k];                        // 计算下一位置的列坐标
            if (x >= 0 && x < m && y >= 0 && y < n && digit(x) + digit(y) <= cnt && !vis[x][y]) // 判断下一格是否满足边界、数位和及未访问条件
                dfs(x, y, cnt);                       // 继续递归搜索下一可达位置
        }
    }
    int wardrobeFinishing(int _m, int _n, int cnt)    // 计算机器人能够到达的格子总数
    {
        m = _m;                                       // 保存网格的行数
        n = _n;                                       // 保存网格的列数
        vis.resize(m, vector<bool>(n));               // 初始化所有格子为未访问状态
        if (digit(0) + digit(0) <= cnt && !vis[0][0]) // 判断起点是否满足进入条件
            dfs(0, 0, cnt);                           // 从左上角起点开始深度优先搜索
        return ret;                                   // 返回机器人能够到达的格子数量
    }
};