// https://leetcode.cn/problems/group-anagrams/

//思路
//如果互为字母异位词：将它们排序之后，两个单词应该是完全相同的
//所以将相同的结果相同的放在相同的key值后，key值为排序后的结果
//哈希表的pair中的second可以放vector
//分好组后直接遍历哈希表，然后将value（也就是pair中的second）直接加进ret
//二维vector是一个一个vector，按照vector的顺序进行存放的，所以可以直接将一维的vector直接追加到二维vector

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> hash;

        for (auto& e : strs)
        {
            string tmp = e;
            std::sort(e.begin(), e.end());
            hash[e].push_back(tmp);
        }
        vector<vector<string>> ret;
        for (auto& [x, y] : hash)
        {
            ret.push_back(y);
        }
        return ret;
    }
};