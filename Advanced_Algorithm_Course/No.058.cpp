// https://leetcode.cn/problems/contains-duplicate/

//思路
//放入哈希表进行计数判断
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> hash;
        for (auto e : nums)
        {
            hash[e]++;
            if (hash[e] > 1) return true;
        }
        return false;
    }
};