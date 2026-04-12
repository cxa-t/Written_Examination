//https://leetcode.cn/problems/fruit-into-baskets/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        int left = 0;
        int right = 0;
        unordered_map<int, int> hash;
        int ret = 0;
        while (right < fruits.size())
        {
            hash[fruits[right]]++;
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)
                    hash.erase(fruits[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};
int main()
{
    Solution su;
    vector<int> v({ 3,3,3,1,2,1,1,2,3,3,4 });
    int k = 5;
    su.totalFruit(v);
    return 0;
}