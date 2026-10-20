// https://leetcode.cn/problems/word-ladder/

class Solution // 定义题解类
{
public: // 公有成员区域
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) // 使用 BFS 求从 beginWord 转换到 endWord 的最短转换序列长度
    {
        unordered_set<string> vis; // 记录已经访问过的单词，避免同一个单词被重复加入队列
        unordered_set<string> hash(wordList.begin(), wordList.end()); // 将 wordList 放入哈希集合中，方便快速判断某个单词是否存在于字典中
        if(hash.count(endWord) == 0) return 0; // 如果目标单词 endWord 不在字典中，根据题意无法完成转换，直接返回0
        queue<string> q; // 定义 BFS 队列，用来保存当前等待继续转换的单词
        q.push(beginWord); // 将起始单词 beginWord 加入队列，从它开始进行广度优先搜索
        vis.insert(beginWord); // 将起始单词标记为已访问，防止后续再次重复搜索 beginWord
        int ret = 1; // 记录当前转换序列的长度，起始单词本身也算一个单词，所以初始值为1
        while(q.size()) // 只要队列不为空，说明还有可以继续向下转换的单词
        {
            int sz = q.size(); // 记录当前 BFS 这一层中单词的数量，保证每次只处理同一层的所有单词
            ret++; // 准备从当前层向下一层进行一次转换，因此转换序列长度加1
            for(int i = 0; i < sz; i++) // 依次处理当前这一层中的所有单词
            {
                string t = q.front(); // 取出队头单词，准备尝试修改它的每一个字符
                q.pop(); // 当前单词已经取出处理，将它从队列中删除
                for(int j = 0; j < t.size(); j++) // 枚举当前单词中的每一个字符位置，尝试只修改其中一个字符
                {
                    string tmp = t; // 复制当前单词，在 tmp 上进行修改，避免直接改变原单词 t
                    for(int k = 'a'; k <= 'z'; k++) // 枚举小写字母 a 到 z，尝试将第 j 个位置替换成不同的字母
                    {
                        tmp[j] = k; // 将 tmp 的第 j 个字符修改为当前枚举到的字母
                        if(!vis.count(tmp) && hash.count(tmp)) // 如果修改后的单词存在于字典中，并且之前没有访问过，说明这是一个合法的新状态
                        {
                            if(tmp == endWord) return ret; // 如果当前新单词就是目标单词，由于 BFS 按层搜索，此时 ret 就是最短转换序列长度
                            vis.insert(tmp); // 将这个新单词标记为已访问，避免以后再次重复搜索
                            q.push(tmp); // 将这个合法的新单词加入队列，等待下一层继续从它进行转换
                        }
                    }
                }
            }
        }
        return 0; // 如果 BFS 搜索结束仍然没有找到 endWord，说明不存在合法的转换序列，返回0
    }
};