//  https://leetcode.cn/problems/broken-calculator/


class Solution // 定义题解类
{
public: // 公有成员区域
    int brokenCalc(int startValue, int target) // 返回从 startValue 变成 target 所需要的最少操作次数
    {
        int ret = 0; // 记录当前已经执行的操作次数
        while (startValue < target) // 当目标值仍然大于起始值时，从 target 反向推导到 startValue
        {
            if (target % 2 == 0) target /= 2; // 如果 target 是偶数，就执行除以2，对应正向操作中的乘以2
            else target += 1; // 如果 target 是奇数，无法直接除以2，就先加1变成偶数，对应正向操作中的减1
            ret++; // 每执行一次反向操作，操作次数加1
        }
        return ret + startValue - target; // 当 target 小于等于 startValue 时，只需要通过不断减1把 startValue 变成 target，因此还需要 startValue-target 次操作
    }
};