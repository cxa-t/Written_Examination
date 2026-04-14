// https://leetcode.cn/problems/find-all-anagrams-in-a-string/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;
        int hash1[26] = { 0 }; // 统计字符串 p 中每个字符出现的个数
        for (auto ch : p) hash1[ch - 'a']++;

        int hash2[26] = { 0 }; // 统计窗⼝⾥⾯的每⼀个字符出现的个数
        int m = p.size();
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            // 进窗⼝ + 维护 count 
            if (++hash2[in - 'a'] <= hash1[in - 'a']) count++;
            if (right - left + 1 > m) // 判断
            {
                char out = s[left++];
                // 出窗⼝ + 维护 count 
                if (hash2[out - 'a']-- <= hash1[out - 'a']) count--;
            }
            // 更新结果
            if (count == m) ret.push_back(left);
        }
        return ret;
    }
};