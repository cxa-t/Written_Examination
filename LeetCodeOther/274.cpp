// https://leetcode.cn/problems/h-index/?envType=study-plan-v2&envId=top-interview-150


class Solution // 定义题解类，使用排序和贪心思想计算科研人员的 H 指数
{
public: // 公有成员区域
    int hIndex(vector<int>& citations) // 返回科研人员的最大 H 指数，即至少有 h 篇论文的引用次数都不小于 h
    {
        int n = citations.size(); // 获取论文的总数量，n 表示一共有多少篇论文
        sort(citations.begin(), citations.end()); // 将所有论文的引用次数按照从小到大排序，方便判断后面有多少篇论文的引用次数满足要求
        for(int i = 0; i < n; i++) // 从引用次数最少的论文开始依次遍历，尝试寻找满足条件的最大 H 指数
            if(citations[i] >= n - i) // 当前下标为 i，从 i 到 n-1 一共有 n-i 篇论文；由于数组已经升序排序，如果当前论文的引用次数不小于 n-i，说明后面这 n-i 篇论文的引用次数也都不小于 n-i，满足 H 指数的定义
                return n - i; // 返回当前满足条件的论文数量 n-i；因为从左往右遍历时 n-i 不断减小，所以第一次满足条件时得到的就是最大的 H 指数
        return 0; // 如果遍历结束仍然没有找到满足条件的位置，说明不存在至少1篇引用次数不小于1的论文，因此 H 指数为0
    }
};