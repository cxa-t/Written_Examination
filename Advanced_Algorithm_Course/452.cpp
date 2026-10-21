//  https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution // 定义题解类
{
public: // 公有成员区域
    int findMinArrowShots(vector<vector<int>>& points) // 返回引爆所有气球所需要的最少箭数，每个气球用区间 [xstart, xend] 表示
    {
        sort(points.begin(), points.end()); // 先按照区间左端点从小到大排序；如果左端点相同，则按照右端点从小到大排序
        int right = points[0][1]; // 记录当前这一组可以被同一支箭射爆的所有气球的公共右边界，先用第一个气球的右端点初始化
        int ret = 1; // 至少需要一支箭，因此箭的数量初始化为1
        for(int i = 1; i < points.size(); i++) // 从第二个气球开始依次判断是否能够和前面的气球共用一支箭
        {
            int a = points[i][0]; // 取出当前气球区间的左端点
            int b = points[i][1]; // 取出当前气球区间的右端点
            if(a <= right) // 如果当前气球的左端点不大于当前公共右边界，说明当前气球和前面这一组气球仍然存在公共重叠区域，可以用同一支箭射爆
            {
                right = min(right, b); // 更新公共重叠区域的右边界，取原来的 right 和当前气球右端点 b 中较小的值
            }
            else // 如果当前气球的左端点已经大于公共右边界，说明它和前面这一组气球没有重叠，不能再使用同一支箭
            {
                ret++; // 需要额外再射一支箭，因此箭的数量加1
                right = b; // 当前气球成为新的一组，用它的右端点重新初始化公共右边界
            }
        }
        return ret; // 返回引爆所有气球所需要的最少箭数
    }
};