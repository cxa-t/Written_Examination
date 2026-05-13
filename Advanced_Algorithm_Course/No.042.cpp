//https://leetcode.cn/problems/minimum-number-of-frogs-croaking/description/

#include<iostream>
#include<string>
#include<unordered_map>
#include <map>
using namespace std;

//思路
//每次都需要把croak全部走一遍，那就模拟状态意思就是当前为r前一个就必是c
//如果遇到c，代表是一轮新的青蛙或者有一个青蛙连续的第二声，题目要求最小
//那就看看k这个位置，有没有已经到头的青蛙，有的话就是它继续叫的，没有就是新的
//这里需要存一些哈希映射
//下面给了几种办法，第三种最通用
class Solution
{
public:
    int minNumberOfFrogs(string s)
    {
        // //1.直接暴力插入映射关系
        // //map<char, char> prevcmap = { {'c','k'},{'r', 'c'},{'o','r'},{'a','o'},{'k','a'} };
        // //2.在不知道多少字符的情况进行遍历插入
        // string tmp = "croak";
        // map<char,char> prevcmap;
        // prevcmap[tmp[0]] = tmp.back();
        // for(int i = 1; i < tmp.size(); i++) prevcmap[tmp[i]] = tmp[i-1];
        // unordered_map<char, int> hash;
        // int n = s.size();
        // int cur = 0;
        // while (cur < n)
        // {
        //     if (s[cur] != 'c' && hash[prevcmap[s[cur]]] == 0) return -1;
        //     if (s[cur] == 'c' && hash[prevcmap[s[cur]]] == 0)
        //         hash[s[cur]]++;
        //     else
        //     {
        //         hash[prevcmap[s[cur]]]--;
        //         hash[s[cur]]++;
        //     }
        //     cur++;
        // }
        // if (hash['c'] || hash['r'] || hash['o'] || hash['a']) return -1;
        // else return hash['k'];

        //3. 使用下标进行映射
        string t = "croak";
        int n = t.size();
        vector<int> hash(n); // 使数组来模拟哈希表
        unordered_map<char, int> index; //[x, x这个字符对应的下标] 
        for (int i = 0; i < n; i++) index[t[i]] = i;

        for (auto ch : s)
        {
            if (ch == 'c')
            {
                if (hash[n - 1] != 0) hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int i = index[ch];
                if (hash[i - 1] == 0) return -1;
                hash[i - 1]--; hash[i]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
            if (hash[i] != 0)
                return -1;
        return hash[n - 1];
    }
};


int main()
{
    string s = "croakcroak";
    Solution().minNumberOfFrogs(s);
	return 0;
}