// https://leetcode.cn/problems/lemonade-change/

class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)             // 判断是否能为所有顾客正确找零
    {
        int five = 0;                                    // 记录当前持有的5元钞票数量
        int ten = 0;                                     // 记录当前持有的10元钞票数量
        for (auto e : bills)                              // 按顾客付款顺序依次处理每张钞票
        {
            if (e == 5)                                   // 顾客支付5元时不需要找零
                five++;                                  // 收下一张5元钞票
            else if (e == 10)                             // 顾客支付10元时需要找回5元
            {
                if (five)                                 // 判断是否有5元钞票可以找零
                {
                    five--;                              // 找出一张5元钞票
                    ten++;                               // 收下一张10元钞票
                }
                else return false;                       // 没有5元钞票时无法完成找零
            }
            else                                         // 顾客支付20元时需要找回15元
            {
                if (five && ten)                         // 优先使用一张10元和一张5元进行找零
                {
                    ten--;                               // 找出一张10元钞票
                    five--;                              // 找出一张5元钞票
                }
                else if (five >= 3)                      // 没有10元时尝试使用三张5元找零
                {
                    five -= 3;                          // 找出三张5元钞票
                }
                else                                    // 两种找零方式都无法满足
                {
                    return false;                       // 无法正确找零直接返回失败
                }
            }
        }
        return true;                                     // 所有顾客都成功找零则返回成功
    }
};