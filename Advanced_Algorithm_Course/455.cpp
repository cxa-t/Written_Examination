// https://leetcode.cn/problems/assign-cookies/


class Solution // 定义题解类
{
public: // 公有成员区域
    int findContentChildren(vector<int>& g, vector<int>& s) // 返回最多可以满足多少个孩子；g 表示孩子的胃口值，s 表示饼干的尺寸
    {
        sort(g.begin(), g.end()); // 将孩子的胃口值从小到大排序，优先满足胃口较小的孩子
        sort(s.begin(), s.end()); // 将饼干尺寸从小到大排序，优先使用较小但能够满足孩子的饼干
        int ret = 0; // 记录当前已经满足的孩子数量
        int j = 0; // j 指向当前还没有使用的饼干位置
        for (int i = 0; i < g.size(); i++) // 从胃口最小的孩子开始依次尝试分配饼干
        {
            while (j < s.size() && g[i] > s[j]) j++; // 如果当前饼干尺寸小于孩子胃口，说明这块饼干无法满足当前孩子，继续寻找更大的饼干
            if (j++ < s.size()) ret++; // 如果当前 j 还没有越界，说明找到了能满足当前孩子的饼干，满足人数加1；随后 j 自增，表示这块饼干已经被使用
        }
        return ret; // 返回最多能够满足的孩子数量
    }
};