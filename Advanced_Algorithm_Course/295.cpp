// https://leetcode.cn/problems/find-median-from-data-stream/


class MedianFinder                                // 使用两个堆动态维护数据流的中位数
{
public:
    MedianFinder()                                // 初始化中位数查找器
    {
    }                                            // 无需额外初始化操作
    void addNum(int num)                          // 向数据流中加入一个新数字
    {
        if (_q_small.size() == _q_big.size())      // 两个堆大小相等时让大根堆多保存一个元素
        {
            if (_q_big.empty() || num <= _q_small.top()) // 大根堆为空或新数字属于较小的一半
            {
                _q_big.push(num);                 // 将新数字直接加入大根堆
            }
            else                                  // 新数字属于较大的一半
            {
                _q_small.push(num);               // 先将新数字加入小根堆
                _q_big.push(_q_small.top());      // 将小根堆最小值移动到大根堆
                _q_small.pop();                   // 删除已经移动到大根堆的元素
            }
        }
        else if (_q_small.size() + 1 == _q_big.size()) // 大根堆比小根堆多一个元素时需要恢复数量平衡
        {
            if (num <= _q_big.top())               // 新数字属于较小的一半
            {
                _q_big.push(num);                 // 先将新数字加入大根堆
                _q_small.push(_q_big.top());      // 将大根堆最大值移动到小根堆
                _q_big.pop();                     // 删除已经移动到小根堆的元素
            }
            else                                  // 新数字属于较大的一半
            {
                _q_small.push(num);               // 将新数字直接加入小根堆
            }
        }
    }
    double findMedian()                           // 返回当前数据流的中位数
    {
        if (_q_big.size() == _q_small.size())      // 元素总数为偶数时两个堆大小相等
            return static_cast<double>((_q_big.top() + _q_small.top()) / 2.0); // 取两个堆顶元素的平均值
        else                                      // 元素总数为奇数时大根堆多一个元素
            return _q_big.top();                  // 大根堆堆顶就是当前中位数
    }
private:
    struct compare_less                           // 定义大根堆的比较规则
    {
        bool operator()(const int& a, const int& b) const // 比较两个元素的大小
        {
            return a < b;                         // 较大的元素具有更高优先级
        }
    };
    struct compare_greater                        // 定义小根堆的比较规则
    {
        bool operator()(const int& a, const int& b) const // 比较两个元素的大小
        {
            return a > b;                         // 较小的元素具有更高优先级
        }
    };
    priority_queue<int, vector<int>, compare_less> _q_big; // 大根堆保存较小的一半数据
    priority_queue<int, vector<int>, compare_greater> _q_small; // 小根堆保存较大的一半数据
};
/**                                              // LeetCode对象调用说明
 * Your MedianFinder object will be instantiated and called as such: // 创建MedianFinder对象
 * MedianFinder* obj = new MedianFinder();        // 动态创建一个中位数查找器
 * obj->addNum(num);                              // 向数据流中加入数字
 * double param_2 = obj->findMedian();            // 获取当前数据流的中位数
 */