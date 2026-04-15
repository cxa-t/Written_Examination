// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ret;// 记录结果
        // 正确hash结果
        unordered_map<string, int> hashwords;
        for (int i = 0; i < words.size(); i++)
            hashwords[words[i]]++;

        int m = words[0].size();//单词长度
        int i = 0;//记录循环开始的起始位置
        while (i < m)
        {
            // 这是初始的起点
            int left = i;
            int right = i;
            int count_words = 0;//窗口内有效的单词个数
            unordered_map<string, int> hashs;//从不同开头需要不同的hash表
            //因为要构造单词 所以不是单纯right到边界 而是right走到不能构造单词时就可以了
            while (right < s.size() && right + m - 1 < s.size())
            {
                //构造一个临时的单词
                string tmp(s.begin() + right, s.begin() + right + m);
                //单词进窗口 进行hash
                if (++hashs[tmp] <= hashwords[tmp])//这里要是单词不在的话[]会插入，value会补0，所以直接用也没事
                    count_words++;
                //窗口内的单词个数多了需要出窗口
                if (((right - left) / m) + 1 > words.size()) //出窗口是从左边构造单词，一定不会越界
                {
                    string tmp(s.begin() + left, s.begin() + left + m);//构造左边的临时单词
                    if (hashs[tmp]-- <= hashwords[tmp]) count_words--;//维护有效单词个数
                    left += m;//直接去到下一个单词
                }
                if (count_words == words.size()) ret.push_back(left);//有效个数=传进来的单词个数表示合法
                right += m;//去下一个单词
            }
            i++;//去下一个初始点位继续
        }
        return ret;
    }
};