// https://leetcode.cn/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

class Solution // 定义题解类，使用哈希计数判断 magazine 中的字符能否组成 ransomNote
{
public: // 公有成员区域
    bool canConstruct(string ransomNote, string magazine) // 判断能否使用 magazine 中的字符构造 ransomNote，每个字符最多只能使用一次
    {
        if(ransomNote.size() > magazine.size()) return false; // 如果赎金信的长度大于杂志的长度，说明杂志中的字符数量一定不够，直接返回false
        int hash[26] = {0}; // 定义长度为26的数组，分别统计26个小写英文字母出现的次数，并将所有元素初始化为0
        for(auto e : magazine) // 遍历 magazine 中的每一个字符，统计杂志中各个字母的数量
            hash[e - 'a']++; // 利用字符与'a'的ASCII码差值作为数组下标，例如'a'对应0、'b'对应1，每出现一次就将对应计数加1
        for(auto e : ransomNote) // 遍历 ransomNote 中的每一个字符，检查杂志中是否有足够的对应字母
        {
            if(--hash[e - 'a'] < 0) // 每使用一个字符，就先将对应字母的剩余数量减1；如果减完后小于0，说明该字母数量不足
                return false; // 如果某个字符的数量不够，就无法构造完整的赎金信，直接返回false
        }
        return true; // 如果所有字符都成功匹配，说明magazine中的字符足够构造ransomNote，返回true
    }
};