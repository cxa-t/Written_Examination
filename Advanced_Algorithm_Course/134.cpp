// https://leetcode.cn/problems/gas-station/

class Solution // 定义题解类
{
public: // 公有成员区域
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) // 返回能够绕环路行驶一圈的起始加油站下标，如果不存在则返回-1
    {
        int n = gas.size(); // 获取加油站的数量
        for (int i = 0; i < n; i++) // 枚举每一个加油站作为可能的起点
        {
            int remanent = 0; // 记录从当前起点i出发后，行驶过程中剩余的汽油量
            int step = 0; // 记录从当前起点已经成功尝试经过了多少个加油站
            for (; step < n; step++) // 最多尝试行驶n个加油站，如果能全部走完就说明可以完成一圈
            {
                int index = (i + step) % n; // 计算当前实际访问的加油站下标，取模用于实现环形遍历
                remanent = remanent + gas[index] - cost[index]; // 在当前加油站加上gas[index]的油，再减去前往下一站所需要的cost[index]油量
                if (remanent < 0) break; // 如果剩余油量小于0，说明无法从当前起点继续前进，立即结束本次尝试
            }
            if (remanent >= 0) return i; // 如果成功走完n步后油量仍然不小于0，说明可以从i出发完成一整圈，返回i
            i += step; // 如果从i出发在step位置失败，则i到i+step之间的位置都不可能作为起点，直接跳过这些位置
        }
        return -1; // 所有可能的起点都无法完成一圈，返回-1
    }
};