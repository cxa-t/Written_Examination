// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int s = numbers[left] + numbers[right];
            if (s < target) left++;
            else if (s > target) right--;
            else return { left + 1, right + 1 };
        }
        return {};
    }
};
