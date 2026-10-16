// https://leetcode.cn/problems/merge-intervals/


class Solution // 定义题解类
{
public: // 公有成员区域
    struct cmp // 定义一个比较器结构体，用于自定义区间的排序规则
    {
        bool operator()(const vector<int>& a, const vector<int>& b) // 重载函数调用运算符，使 cmp 可以作为 sort 的比较函数使用
        {
            return a[0] < b[0]; // 按照每个区间的左端点从小到大排序，左端点较小的区间排在前面
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) // 合并所有有重叠的区间，并返回合并后的区间集合
    {
        sort(intervals.begin(), intervals.end(), cmp()); // 按照区间左端点从小到大排序，方便后续从左到右依次合并
        int n = intervals.size(); // 获取区间的数量
        vector<vector<int>> ret; // 定义结果数组，用来保存最终合并完成的区间
        int left = intervals[0][0]; // 用第一个区间的左端点初始化当前待合并区间的左边界
        int right = intervals[0][1]; // 用第一个区间的右端点初始化当前待合并区间的右边界
        for (int i = 1; i < n; i++) // 从第二个区间开始依次遍历，判断是否可以和当前区间合并
        {
            int a = intervals[i][0]; // 取出当前区间的左端点
            int b = intervals[i][1]; // 取出当前区间的右端点
            if (a <= right) // 如果当前区间的左端点小于等于当前合并区间的右端点，说明两个区间存在重叠，可以进行合并
            {
                right = max(right, b); // 更新合并区间的右端点，取当前右端点和新区间右端点中的较大值
            }
            else // 如果当前区间的左端点大于当前合并区间的右端点，说明两个区间没有重叠
            {
                ret.push_back({ left, right }); // 将前面已经合并完成的区间加入结果数组
                left = intervals[i][0]; // 以当前新区间的左端点作为下一段待合并区间的左边界
                right = intervals[i][1]; // 以当前新区间的右端点作为下一段待合并区间的右边界
            }
        }
        ret.push_back({ left, right }); // 循环结束后，将最后一段还没有加入结果数组的区间加入 ret
        return ret; // 返回所有合并完成后的区间
    }
};