// https://leetcode.cn/problems/course-schedule/


class Solution // 定义题解类，使用 BFS 拓扑排序判断是否能够完成所有课程
{
public: // 公有成员区域
    bool canFinish(int n, vector<vector<int>>& prerequisites) // 判断能否完成全部 n 门课程，如果课程之间存在循环依赖则返回 false，否则返回 true
    {
        unordered_map<int, vector<int>> edges; // 定义邻接表存储有向图，edges[b] 表示学完课程 b 后可以继续学习哪些课程
        vector<int> in(n); // 定义入度数组，in[i] 表示课程 i 有多少门前置课程尚未完成，初始值全部为0
        for(auto e : prerequisites) // 遍历所有课程的先修关系，建立有向图并统计每门课程的入度
        {
            int a = e[0]; // 获取当前需要学习的课程 a
            int b = e[1]; // 获取课程 a 的前置课程 b，必须先学习 b 才能学习 a
            edges[b].push_back(a); // 建立一条从 b 指向 a 的有向边，表示课程 a 依赖课程 b
            in[a]++; // 课程 a 多了一条指向它的边，因此将课程 a 的入度加1
        }
        queue<int> q; // 创建 BFS 队列，用于存储当前入度为0、可以直接学习的课程
        for(int i = 0; i < n; i++) // 遍历所有课程，寻找入度为0的课程作为拓扑排序的起点
        {
            if(in[i] == 0) // 如果当前课程的入度为0，说明它没有尚未完成的前置课程，可以直接学习
                q.push(i); // 将当前课程加入队列，等待后续处理
        }
        while(!q.empty()) // 只要队列不为空，说明还有可以学习的课程，继续执行拓扑排序
        {
            int t = q.front(); // 取出队头课程 t，表示当前准备完成这门课程
            q.pop(); // 将课程 t 从队列中删除，表示这门课程已经被处理
            for(int e : edges[t]) // 遍历所有依赖课程 t 的后续课程，即所有从 t 出发的有向边所指向的课程
            {
                in[e]--; // 由于课程 t 已经完成，课程 e 就少了一门需要完成的前置课程，因此将课程 e 的入度减1
                if(in[e] == 0) q.push(e); // 如果课程 e 的入度减为0，说明它的所有前置课程都已经完成，将它加入队列等待学习
            }
        }
        for(int i = 0; i < n; i++) // 拓扑排序结束后，遍历所有课程，检查是否还有课程存在未消除的依赖关系
        {
            if(in[i]) return false; // 如果某门课程的入度仍然不为0，说明图中存在环形依赖，导致部分课程无法完成，返回false
        }
        return true; // 如果所有课程的入度都已经变为0，说明所有课程都可以按照某种顺序完成，返回true
    }
};