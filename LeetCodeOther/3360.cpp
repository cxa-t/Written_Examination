// https://leetcode.cn/problems/stone-removal-game/?envType=daily-question&envId=2026-11-26

class Solution // 定义题解类，使用模拟法判断Alice能否获胜
{
public: // 公有成员区域
    bool canAliceWin(int n) // 判断Alice在移除石头游戏中能否获胜，n表示初始石头数量
    {
        int pick = 10; // 定义每一轮需要取走的石头数量，第一轮需要取走10个，之后每轮减少1个
        while(n >= pick) // 如果当前剩余石头数量不少于本轮需要取走的数量，说明当前玩家能够成功取石头
        {
            n -= pick; // 当前玩家取走pick个石头，更新剩余石头数量
            pick--; // 当前回合结束，下一位玩家需要取走的石头数量减少1
        }
        return (10 - pick) % 2 == 1; // 10-pick表示成功取石头的总次数，如果次数为奇数，说明Alice完成最后一次操作，Bob无法继续，Alice获胜；否则Alice失败
    }
};