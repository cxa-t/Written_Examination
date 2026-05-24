// https://leetcode.cn/problems/contains-duplicate-ii/

//思路
//遍历数组，如果当前元素在哈希表里，则判断下标是不是符合要求，符合直接返回true
//不符合就下一个元素，如果不在就将元素存入哈希表内
//因为从左往右进行遍历，所以哈希表里保证存放的都是该元素最小的那个下标
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(nums[i]))
                if (i - hash[nums[i]] <= k)
                    return true;
            hash[nums[i]] = i;
        }
        return false;
    }
};