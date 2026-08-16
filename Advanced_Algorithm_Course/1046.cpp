// https://leetcode.cn/problems/last-stone-weight/

class Solution
{
public:
    int lastStoneWeight(vector<int>& stones)              // 返回最后剩下石头的重量
    {
        priority_queue<int> q(stones.begin(), stones.end()); // 将所有石头放入大根堆中
        while (q.size() > 1)                               // 至少还有两块石头时继续碰撞
        {
            int a = q.top();                              // 取出当前最重的石头
            q.pop();                                      // 删除最重的石头
            int b = q.top();                              // 取出当前第二重的石头
            q.pop();                                      // 删除第二重的石头
            if (a > b) q.push(a - b);                      // 两块石头重量不同则将差值重新放入堆中
        }
        return q.size() == 0 ? 0 : q.top();               // 没有石头返回0，否则返回最后一块石头
    }
};