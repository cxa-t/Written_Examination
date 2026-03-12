#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/

class Solution 
{
public:
    vector<int> twoSum(vector<int>& price, int target)
    {
        vector<int> ret;
        int lfet = 0;
        int right = price.size() - 1;
        while (lfet < right)
        {
            if (price[lfet] + price[right] == target)
            {
                ret.push_back(price[lfet]);
                ret.push_back(price[right]);
                break;
            }
            else if (price[lfet] + price[right] > target)
            {
                right--;
            }
            else
            {
                lfet++;
            }
        }
        return ret;
    }
};