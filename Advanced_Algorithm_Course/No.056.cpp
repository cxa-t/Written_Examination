// https://leetcode.cn/problems/two-sum/


// 思路
// 每次都在前面找target-nums[i]的值，找不到就把当前nums的元素放进去
// 题目要求不能使用相同的元素，刚好哈希可以进行去重。
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if (hash.count(x)) return { hash[x],i };
            else hash[nums[i]] = i;
        }
        return { -1, -1 };
    }
};