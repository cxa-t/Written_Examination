// https://leetcode.cn/problems/word-pattern/?envType=study-plan-v2&envId=top-interview-150


class Solution // 定义题解类，使用双指针分割字符串和双向哈希映射判断字符串是否符合指定的单词规律
{
public: // 公有成员区域
    bool wordPattern(string pattern, string s) // 判断字符串s中的单词是否与pattern中的字符满足一一对应关系，满足则返回true，否则返回false
    {
        vector<string> words; // 定义字符串数组，用来保存从字符串s中分割出来的所有单词
        int left = 0; // 定义左指针，指向当前需要提取的单词的起始位置
        while(left < s.size()) // 只要左指针没有到达字符串末尾，就继续从字符串中提取单词
        {
            int right = left; // 定义右指针，从当前单词的起始位置开始，向后寻找单词的结束位置
            while(right < s.size() && s[right] != ' ') right++; // 如果右指针没有越界，并且当前字符不是空格，就继续向后移动，直到找到空格或者到达字符串末尾
            words.emplace_back(s.substr(left, right - left)); // 使用substr从left位置开始截取长度为right-left的子字符串，并通过emplace_back将当前单词添加到words数组末尾
            left = right + 1; // 将左指针移动到当前单词结束位置的下一个位置，跳过单词后面的空格，准备提取下一个单词
        }
        if(words.size() != pattern.size()) return false; // 如果分割得到的单词数量与pattern中的字符数量不相等，说明无法建立一一对应关系，直接返回false
        unordered_map<char, string> hash; // 定义正向哈希表，记录pattern中的字符到words中单词的映射关系，保证同一个字符只能对应同一个单词
        unordered_map<string, char> rhash; // 定义反向哈希表，记录words中的单词到pattern中字符的映射关系，保证同一个单词只能对应同一个字符
        for(int i = 0; i < pattern.size(); i++) // 同时遍历pattern中的每个字符和words中对应位置的单词，逐个检查是否满足双向一一对应关系
        {
            if(hash.count(pattern[i]) && hash[pattern[i]] != words[i]) // 如果当前字符已经存在于正向哈希表中，但是之前映射的单词与当前单词不同，说明同一个字符对应了两个不同的单词
                return false; // 正向映射发生冲突，不满足题目要求，直接返回false
            if(rhash.count(words[i]) && rhash[words[i]] != pattern[i]) // 如果当前单词已经存在于反向哈希表中，但是之前映射的字符与当前字符不同，说明两个不同的字符对应了同一个单词
                return false; // 反向映射发生冲突，不满足题目要求，直接返回false
            hash[pattern[i]] = words[i]; // 建立或更新当前字符到当前单词的正向映射，例如将字符'a'映射到单词"dog"
            rhash[words[i]] = pattern[i]; // 建立或更新当前单词到当前字符的反向映射，例如将单词"dog"映射到字符'a'
        }
        return true; // 如果所有字符和单词都没有发生正向或反向映射冲突，说明满足一一对应关系，返回true
    }
};
