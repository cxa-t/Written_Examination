// https://leetcode.cn/problems/non-overlapping-intervals/

class Solution // 定义题解类
{
public: // 公有成员区域
    int eraseOverlapIntervals(vector<vector<int>>& intervals) // 返回为了使所有区间互不重叠，最少需要删除的区间数量
    {
        sort(intervals.begin(), intervals.end()); // 按照区间左端点从小到大排序；如果左端点相同，则继续按照右端点从小到大排序
        int ret = 0; // 记录需要删除的区间数量
        int left = intervals[0][0], right = intervals[0][1]; // 用第一个区间初始化当前保留下来的区间范围，left 为左端点，right 为右端点
        for (int i = 1; i < intervals.size(); i++) // 从第二个区间开始依次判断是否与当前保留区间发生重叠
        {
            int a = intervals[i][0], b = intervals[i][1]; // 取出当前区间的左端点 a 和右端点 b
            if (a < right) // 如果当前区间左端点小于当前保留区间的右端点，说明两个区间发生重叠
            {
                ret++; // 出现重叠时必须删除其中一个区间，因此删除数量加1
                right = min(right, b); // 保留右端点更小的区间，因为结束得越早，就越容易给后面的区间留出空间，从而减少后续重叠
            }
            else // 如果当前区间左端点大于等于 right，说明当前区间和前一个保留区间不重叠
            {
                right = b; // 保留当前区间，并将 right 更新为当前区间的右端点，继续和后面的区间比较
            }
        }
        return ret; // 返回为了使所有区间互不重叠所需要删除的最少区间数量
    }
};