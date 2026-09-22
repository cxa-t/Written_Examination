// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/


class Solution
{
public:
    int halveArray(vector<int>& nums)              // 计算将数组总和至少减少一半所需的最少操作次数
    {
        priority_queue<double> heap;               // 使用大根堆每次取出当前最大的数字
        double sum = 0;                            // 保存数组当前总和
        for (auto e : nums)                         // 遍历数组中的所有元素
        {
            heap.push(e);                          // 将当前元素加入大根堆
            sum += e;                              // 累加得到数组总和
        }
        int ret = 0;                               // 记录执行减半操作的次数
        double res = sum / 2.0;                    // 记录数组总和需要降低到的目标值
        while (res < sum)                           // 当前总和仍大于目标值时继续操作
        {
            double numtop = heap.top();            // 取出当前最大的数字
            heap.pop();                            // 将当前最大数字移出堆
            sum -= numtop / 2.0;                   // 将最大数字减半后同步减少当前总和
            heap.push(numtop / 2.0);               // 将减半后的数字重新放入大根堆
            ret++;                                 // 操作次数加一
        }
        return ret;                                // 返回将数组总和至少减半的最少操作次数
    }
};