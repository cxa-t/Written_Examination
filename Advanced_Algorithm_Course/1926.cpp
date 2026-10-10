//  https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/

class Solution 
{
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) // 返回从入口到最近出口的最短步数
    {
        int dx[4] = {-1,1,0,0};                                      // 定义上下左右四个方向的行偏移
        int dy[4] = {0,0,-1,1};                                      // 定义上下左右四个方向的列偏移
        queue<pair<int, int>> q;                                     // 使用队列进行广度优先搜索
        int m = maze.size();                                         // 获取迷宫的行数
        int n = maze[0].size();                                      // 获取迷宫的列数
        q.push({entrance[0], entrance[1]});                          // 将入口位置加入队列
        vector<vector<bool>> vis(m, vector<bool>(n));                // 标记每个位置是否已经访问
        vis[entrance[0]][entrance[1]] = true;                        // 标记入口位置已经访问
        int step = 0;                                                // 记录从入口出发的当前步数
        while(q.size())                                              // 队列不为空时继续分层搜索
        {
            step++;                                                  // 进入下一层时步数加一
            int sz = q.size();                                       // 记录当前层需要处理的节点数量
            for(int i = 0; i < sz; i++)                              // 遍历当前层的所有位置
            {
                auto [a, b] = q.front();                             // 获取当前队头位置坐标
                q.pop();                                             // 将当前位置移出队列
                for(int j = 0; j < 4; j++)                           // 枚举当前位置的四个相邻方向
                {
                    int x = a + dx[j];                               // 计算相邻位置的行坐标
                    int y = b + dy[j];                               // 计算相邻位置的列坐标
                    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.' && !vis[x][y]) // 判断相邻位置是否可以到达且未访问
                    {
                        if(x == 0 || x == m - 1 || y == 0 || y == n - 1) return step; // 到达边界空格时返回最短步数
                        q.push({x,y});                                // 将可继续搜索的位置加入队列
                        vis[x][y] = true;                             // 标记当前位置已经访问
                    }
                }
            }
        }
        return -1;                                                   // 无法到达任何出口时返回-1
    }
};