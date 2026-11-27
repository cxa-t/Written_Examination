// https://leetcode.cn/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

class Solution // 定义题解类，使用区间合并的思想将新区间插入已有的有序区间数组中
{
public: // 公有成员区域
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) // 将新区间newInterval插入intervals中，并合并所有重叠区间，返回最终结果
    {
        vector<vector<int>> ret; // 定义二维数组ret，用来保存插入新区间并完成合并后的所有区间
        int index = 0; // 定义下标index，用来遍历原区间数组，初始指向第一个区间
        while(index < intervals.size() && intervals[index][1] < newInterval[0]) // 第一阶段：如果当前区间的右端点小于新区间的左端点，说明当前区间完全位于新区间左侧，与新区间没有重叠
        {
            ret.push_back(intervals[index]); // 当前区间与新区间没有重叠，可以直接加入结果数组，不需要进行合并
            index++; // 下标向后移动，继续检查下一个区间是否位于新区间左侧
        }
        while(index < intervals.size() && intervals[index][0] <= newInterval[1]) // 第二阶段：如果当前区间的左端点小于等于新区间的右端点，说明当前区间与新区间存在重叠或端点相接，需要进行合并
        {
            newInterval[0] = min(intervals[index][0], newInterval[0]); // 取当前区间和新区间左端点的较小值，作为合并后新区间的左端点
            newInterval[1] = max(intervals[index][1], newInterval[1]); // 取当前区间和新区间右端点的较大值，作为合并后新区间的右端点
            index++; // 当前区间已经合并到新区间中，继续向后检查是否还有其他区间与合并后的新区间重叠
        }
        ret.push_back(newInterval); // 前两个阶段结束后，新区间已经完成所有必要的合并，将合并后的新区间加入结果数组
        while(index < intervals.size()) // 第三阶段：遍历剩余区间，这些区间全部位于合并后的新区间右侧，不会再发生重叠
        {
            ret.push_back(intervals[index]); // 将当前不重叠的区间直接添加到结果数组末尾
            index++; // 下标向后移动，继续处理下一个剩余区间
        }
        return ret; // 返回插入新区间并合并所有重叠区间后的结果数组
    }
};