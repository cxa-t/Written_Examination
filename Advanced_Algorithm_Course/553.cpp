// https://leetcode.cn/problems/optimal-division/

class Solution 
{
public:
    string optimalDivision(vector<int>& nums)                    // 返回能使除法表达式结果最大的字符串形式
    {
        int n = nums.size();                                     // 获取数组中数字的个数
        if(n == 1) return to_string(nums[0]);                     // 只有一个数字时直接返回该数字
        if(n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]); // 两个数字时只能直接相除
        string ret;                                               // 保存最终构造出的最优表达式
        ret += to_string(nums[0]) + "/(" + to_string(nums[1]);    // 将第一个数字除以后面所有数字组成的整体
        for(int i = 2; i < n; i++)                               // 从第三个数字开始依次拼接除法表达式
        {
            ret += "/" + to_string(nums[i]);                      // 将当前数字加入括号中的连续除法
        }
        ret += ")";                                               // 补上右括号完成表达式
        return ret;                                               // 返回构造后的最优除法表达式
    }
};