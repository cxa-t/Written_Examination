// https://leetcode.cn/problems/top-k-frequent-words/


class Solution {
public:
    struct cmp                                                // 定义优先队列的比较规则
    {
        bool operator()(const pair<string, int>& e1, const pair<string, int>& e2) // 比较两个单词及其出现次数
        {
            if (e1.second == e2.second)                        // 出现次数相同时比较字典序
            {
                return e1.first < e2.first;                    // 字典序较大的单词优先出堆
            }
            else                                              // 出现次数不同时比较频率
            {
                return e1.second > e2.second;                  // 出现次数较少的单词优先保留在堆顶
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k)  // 返回出现频率最高的前k个单词
    {
        unordered_map<string, int> hash;                       // 统计每个单词出现的次数
        vector<string> ret(k);                                 // 保存最终的前k个高频单词
        for (auto& e : words) hash[e]++;                        // 遍历所有单词并统计出现频率
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> q; // 建立大小最多为k的优先队列
        for (auto& e : hash)                                    // 遍历每个单词及其出现次数
        {
            q.push(e);                                         // 将当前单词及频率加入优先队列
            if (q.size() > k) q.pop();                          // 超过k个元素时删除当前优先级最低的元素
        }
        for (int i = k - 1; i >= 0; i--)                        // 从后向前填充最终答案
        {
            ret[i] = q.top().first;                            // 将堆顶单词放到对应结果位置
            q.pop();                                           // 删除已经加入结果的单词
        }
        return ret;                                            // 返回前k个高频单词
    }
};