// https://leetcode.cn/problems/check-permutation-lcci/


// 思路
// 将第一个字符串当作存入哈希表中当作标准答案
// 然后将第二个字符串恢复第一个字符串的哈希表
// 恢复完成后检查哈希表是否为空，为空则互为重排
class Solution
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        unordered_map<char, int> hash;
        for (char e : s1) hash[e]++;
        for (char e : s2)
        {
            hash[e]--;
            if (hash[e] < 0) return false;
        }
        for (char e : s1)
        {
            if (hash[e] > 0) return false;
        }
        return true;
    }
};