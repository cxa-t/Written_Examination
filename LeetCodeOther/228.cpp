// https://leetcode.cn/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> ret; // 存储最终结果，每个字符串表示一个连续区间
        int n = nums.size(); // 获取数组长度
        int left = 0; // 左指针，表示当前连续区间的起始位置

        while(left < n) // 只要左指针没有遍历完整个数组，就继续寻找区间
        {
            int right = left; // 右指针从左指针的位置开始，寻找当前连续区间的结束位置

            // 不断向后寻找连续元素
            // right + 1 < n：保证右指针的下一个位置没有越界
            // nums[right + 1] == nums[right] + 1：判断相邻两个元素是否连续
            // 使用 long long 是为了避免 nums[right] 为 INT_MAX 时，加1发生整数溢出
            while(right + 1 < n && (long long)nums[right + 1] == (long long)nums[right] + 1)
                right++; // 如果连续，右指针向后移动，继续寻找区间的结束位置

            // 判断当前区间是否只有一个元素
            if(left == right)
                ret.push_back(to_string(nums[left])); // 只有一个元素，直接将该数字转换为字符串并加入结果
            else
                ret.push_back(to_string(nums[left]) + "->" + to_string(nums[right])); // 有多个连续元素，拼接成 起始值->结束值 的形式

            // 跳过当前已经处理完的区间，寻找下一个区间
            left = right + 1; // 左指针移动到当前区间结束位置的下一个位置
        }

        return ret; // 返回所有连续区间组成的结果
    }
};