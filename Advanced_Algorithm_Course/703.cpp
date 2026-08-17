// https://leetcode.cn/problems/kth-largest-element-in-a-stream/


class KthLargest
{
public:
    KthLargest(int k, vector<int>& nums)                   // 初始化第k大元素的数据结构
    {
        _k = k;                                            // 保存需要寻找的第k大
        for (auto e : nums)                                 // 遍历初始数组中的所有元素
        {
            q.push(e);                                     // 将当前元素加入小根堆
            if (q.size() > _k) q.pop();                     // 超过k个元素时删除最小元素
        }
    }

    int add(int val)                                       // 添加新元素并返回当前第k大元素
    {
        q.push(val);                                       // 将新元素加入小根堆
        if (q.size() > _k) q.pop();                         // 只保留当前最大的k个元素
        return q.top();                                    // 堆顶就是当前第k大的元素
    }
private:
    priority_queue<int, vector<int>, greater<int>> q;      // 小根堆保存当前最大的k个元素
    int _k;                                                // 保存k的值
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */