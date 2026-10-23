// https://leetcode.cn/problems/greatest-sum-divisible-by-three/


class Solution // 定义题解类
{
public: // 公有成员区域
    int maxSumDivThree(vector<int>& nums) // 返回 nums 中选取若干数字后，使它们的总和能够被3整除的最大总和
    {
        const int INF = 0x3f3f3f3f; // 定义一个足够大的数，用来表示当前还没有找到对应的数字
        int sum = 0; // 记录所有数字的总和
        int x1 = INF, x2 = INF, y1 = INF, y2 = INF; // x1、x2保存余数为1的最小两个数字，y1、y2保存余数为2的最小两个数字
        for(auto x : nums) // 遍历 nums 中的每一个数字
        {
            sum += x; // 将当前数字加入总和
            if(x % 3 == 1) // 如果当前数字除以3的余数为1，将它加入余数为1的数字集合
            {
                if(x < x1) // 如果当前数字比目前最小的余数为1的数字还小
                {
                    x2 = x1; // 原来的最小值变成第二小值
                    x1 = x; // 当前数字成为最小值
                }
                else if(x < x2) x2 = x; // 如果当前数字比第二小值还小，则更新第二小值
            }
            else if(x % 3 == 2) // 如果当前数字除以3的余数为2，将它加入余数为2的数字集合
            {
                if(x < y1) // 如果当前数字比目前最小的余数为2的数字还小
                {
                    y2 = y1; // 原来的最小值变成第二小值
                    y1 = x; // 当前数字成为最小值
                }
                else if(x < y2) y2 = x; // 如果当前数字比第二小值还小，则更新第二小值
            }
        }
        if(sum % 3 == 0) return sum; // 如果所有数字的总和本身就是3的倍数，不需要删除任何数字，直接返回总和
        else if(sum % 3 == 1) return max(sum - x1, sum - y1 - y2); // 如果总和除以3余1，可以删除一个最小的余1数字，或者删除两个最小的余2数字，选择删除数字总和更小的方案
        else return max(sum - y1, sum - x1 - x2); // 如果总和除以3余2，可以删除一个最小的余2数字，或者删除两个最小的余1数字，选择删除数字总和更小的方案
    }
};