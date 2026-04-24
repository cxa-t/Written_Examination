// https://leetcode.cn/problems/minimum-discards-to-balance-inventory/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m)
    {
        //w窗口最大值
        //m hash表最大值
        unordered_map<int, int> hash;
        int left = 0;
        int right = 0;
        int ret = 0;
        while (right < arrivals.size())
        {
            int& cur = arrivals[right];
            hash[cur]++;//进入窗口

            if (right - left + 1 > w)
            {
                if (arrivals[left] == -1)
                    left++;
                else
                {
                    --hash[arrivals[left]];
                    if (hash[arrivals[left]] == 0)
                        hash.erase(arrivals[left]);
                    left++;
                }
            }

            if (hash[cur] > m)
            {
                ret++;
                hash[cur]--;
                cur = -1;//软删除
            }

            right++;
        }
        return ret;
    }
};

int main()
{
    Solution su;
    vector<int> nums = { 10,4,3,6,4,5,6,1,4 };
    int w = 7;
    int m = 1;
    su.minArrivalsToDiscard(nums, w, m);
    return 0;
}