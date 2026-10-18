// https://leetcode.cn/problems/minimum-genetic-mutation/


class Solution // 定义题解类
{
public: // 公有成员区域
    int minMutation(string startGene, string endGene, vector<string>& bank) // 使用 BFS 求从 startGene 变成 endGene 所需要的最少基因突变次数
    {
        unordered_set<string> hash(bank.begin(), bank.end()); // 将基因库 bank 放入哈希集合中，方便 O(1) 判断某个基因是否是合法基因
        unordered_set<string> vis; // 记录已经访问过的基因，避免同一个基因被重复加入队列
        string change = "ACGT"; // 每个基因位置只能突变成 A、C、G、T 这4种字符之一
        if (startGene == endGene) return 0; // 如果起始基因和目标基因相同，不需要进行任何突变，直接返回0
        if (hash.count(endGene) == 0) return -1; // 如果目标基因不在基因库中，根据题意不可能合法突变到目标基因，直接返回-1
        queue<string> q; // 定义 BFS 队列，用来保存当前等待搜索的基因
        q.push(startGene); // 将起始基因加入队列，从它开始进行广度优先搜索
        vis.insert(startGene); // 将起始基因标记为已经访问，防止后续再次回到起始基因
        int ret = 0; // 记录当前已经进行的突变次数，也就是 BFS 搜索的层数
        while (q.size()) // 只要队列不为空，说明还有可以继续搜索的基因
        {
            ret++; // 每向外扩展一层，就表示又进行了一次基因突变
            int sz = q.size(); // 记录当前这一层的基因数量，只处理当前层，保证 BFS 按层搜索
            for (int i = 0; i < sz; i++) // 依次处理当前这一层中的所有基因
            {
                string t = q.front(); // 取出队头基因，准备尝试修改它的每一个位置
                q.pop(); // 当前基因已经取出处理，将它从队列中删除
                for (int j = 0; j < 8; j++) // 枚举基因字符串的8个位置，尝试让其中一个位置发生突变
                {
                    string tmp = t; // 复制当前基因，后续在 tmp 上修改，避免直接改变原来的基因 t
                    for (int k = 0; k < 4; k++) // 当前第 j 个位置分别尝试修改成 A、C、G、T 四种字符
                    {
                        tmp[j] = change[k]; // 将基因的第 j 个位置修改成当前枚举到的字符
                        if (hash.count(tmp) && !vis.count(tmp)) // 如果修改后的基因存在于基因库中，并且之前没有访问过，说明它是一个合法的新状态
                        {
                            if (tmp == endGene) return ret; // 如果当前突变后已经得到目标基因，由于 BFS 按层搜索，此时 ret 就是最少突变次数
                            q.push(tmp); // 将这个合法的新基因加入队列，等待下一层继续从它进行突变
                            vis.insert(tmp); // 将该基因标记为已访问，避免后续重复搜索相同状态
                        }
                    }
                }
            }
        }
        return -1; // 如果 BFS 搜索结束仍然没有找到目标基因，说明无法通过合法突变到达 endGene，返回-1
    }
};