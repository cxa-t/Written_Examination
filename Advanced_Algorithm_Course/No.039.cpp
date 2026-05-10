// https://leetcode.cn/problems/teemo-attacking/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int>& t, int duration)
    {
        //思路：
        //实时维护一个变量 finalt，用来记录当前中毒状态会持续到哪一秒
        //情况 A：新的攻击开始时，旧的中毒已结束
        //这说明中间有“清醒期”。这次攻击会提供一个完整的 duration 时长
        //情况 B：新的攻击开始时，还在中毒中（发生重叠）
        //这次攻击会重置中毒时间，但由于之前已经在中毒了，只能加上新延展出来的部分
        //cur + duration - 1 是这次攻击理论上的结束点 减去 finalt（旧的结束点）
        //得到的就是因为这次攻击而额外增加的秒数。
        //每次循环结束都要更新 finalt = cur + duration - 1，确保下一次判断使用的是最新的截止时间，也就是最新中毒后的最后一秒
        int n = t.size();
        int ret = 0;
        int finalt = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = t[i];
            if (cur > finalt)
                ret += duration;
            else
                ret += (cur + duration - 1 - finalt);
            finalt = duration + cur - 1;
        }
        return ret;
    }
};

int main()
{
    vector<int> t = { 0,23,124 };
    int d = 1;
    Solution().findPoisonedDuration(t, d);
    return 0;
}