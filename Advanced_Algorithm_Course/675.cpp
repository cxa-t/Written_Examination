// https://leetcode.cn/problems/cut-off-trees-for-golf-event/


class Solution // 定义题解类，使用排序和广度优先搜索 BFS 求砍完所有树需要走的最少步数
{
public: // 公有成员区域
    int m; // 记录森林的行数，方便 BFS 判断当前位置是否越界
    int n; // 记录森林的列数，方便 BFS 判断当前位置是否越界
    int cutOffTree(vector<vector<int>>& forest) // 按照树的高度从小到大依次砍树，返回砍完所有树需要走的最少步数，无法完成则返回-1
    {
        m = forest.size(); // 获取森林的行数
        n = forest[0].size(); // 获取森林的列数
        vector<vector<int>> index; // 创建数组，用来保存所有需要砍伐的树的坐标，每个元素包含行下标和列下标
        for(int i = 0; i < m; i++) // 遍历森林中的每一行
        {
            for(int j = 0; j < n; j++) // 遍历当前行中的每一列
            {
                if(forest[i][j] > 1) // 如果当前位置的值大于1，说明这里存在一棵需要砍伐的树
                {
                    index.push_back({i,j}); // 将当前树的坐标(i,j)加入数组，方便后续按照树的高度排序
                }
            }
        }
        sort(index.begin(), index.end(), [&](const vector<int>& p1, const vector<int>& p2) -> bool // 使用 Lambda 表达式自定义排序规则，按照树的高度从小到大排序
        {
            return forest[p1[0]][p1[1]] < forest[p2[0]][p2[1]]; // 比较两棵树所在位置的高度，高度较小的树排在前面，保证按照规定顺序砍树
        });
        int ret = 0; // 记录砍完所有树需要行走的总步数
        int starti = 0; // 记录当前出发位置的行下标，初始位置为(0,0)
        int startj = 0; // 记录当前出发位置的列下标，初始位置为(0,0)
        for(auto& e : index) // 按照树的高度从小到大依次遍历所有需要砍伐的树
        {
            int step = bfs(forest,starti,startj,e[0],e[1]); // 使用 BFS 计算从当前位置(starti,startj)走到目标树(e[0],e[1])的最短距离
            if(step == -1) return -1; // 如果 BFS 返回-1，说明当前无法到达目标树，因此无法砍完所有树，直接返回-1
            ret += step; // 将走到当前目标树所需要的最少步数累加到总步数中
            starti = e[0]; // 成功到达并砍掉当前树后，将当前位置的行下标更新为这棵树的行下标
            startj = e[1]; // 成功到达并砍掉当前树后，将当前位置的列下标更新为这棵树的列下标
        }
        return ret; // 所有树都已经按照高度顺序处理完成，返回行走的最少总步数
    }
    bool vis[51][51]; // 定义二维访问标记数组，记录 BFS 过程中哪些位置已经访问过，避免重复搜索
    int dx[4] = {0, 0, 1, -1}; // 定义上下左右四个方向对应的行偏移量，依次表示左、右、下、上
    int dy[4] = {-1, 1, 0, 0}; // 定义上下左右四个方向对应的列偏移量，与 dx 配合实现四个方向的移动
    int bfs(vector<vector<int>>& forest,int starti,int startj,int endi,int endj) // 使用 BFS 计算从起点(starti,startj)到终点(endi,endj)的最少移动步数
    {
        if(starti == endi && startj == endj) return 0; // 如果起点和终点是同一个位置，说明不需要移动，直接返回0
        queue<pair<int, int>> q; // 创建 BFS 队列，每个元素保存一个位置的行下标和列下标
        memset(vis, 0, sizeof(vis)); // 每次进行新的 BFS 前，将访问标记数组全部清零，避免上一次搜索影响本次搜索
        q.push({starti,startj}); // 将当前起点加入队列，作为 BFS 搜索的第一层
        vis[starti][startj] = true; // 将起点标记为已经访问，防止后续重复将起点加入队列
        int step = 0; // 记录从起点出发已经移动的步数，也就是 BFS 搜索的层数
        while(q.size()) // 只要队列不为空，说明还有可以继续搜索的位置
        {
            step++; // 每向外扩展一层，就表示从当前层的位置再移动一步
            int sz = q.size(); // 记录当前 BFS 这一层中的位置数量，保证每次只处理同一层的所有位置
            while(sz--) // 依次处理当前这一层中的所有位置，处理完后再进入下一层
            {
                auto [a, b] = q.front(); // 取出队头位置的行下标a和列下标b，准备向四个方向扩展
                q.pop(); // 将当前已经取出的位置从队列中删除
                for(int i = 0; i < 4; i++) // 枚举当前位置的四个相邻方向，尝试向左、右、下、上移动
                {
                    int x = a + dx[i]; // 根据当前方向的行偏移量，计算下一个位置的行下标
                    int y = b + dy[i]; // 根据当前方向的列偏移量，计算下一个位置的列下标
                    if(x >= 0 && x < m && y >= 0 && y < n && forest[x][y] != 0 && !vis[x][y]) // 判断新位置是否在森林范围内、是否不是障碍物，以及之前是否没有访问过
                    {
                        if(x == endi && y == endj) return step; // 如果当前新位置就是目标树，说明已经找到最短路径，直接返回当前移动步数
                        q.push({x, y}); // 如果当前位置合法且不是终点，就将它加入队列，等待下一层继续向四周搜索
                        vis[x][y] = true; // 将新位置标记为已访问，避免其他路径重复将它加入队列
                    }
                }
            }
        }
        return -1; // 如果队列已经为空仍然没有找到目标位置，说明起点无法到达终点，返回-1
    }
};