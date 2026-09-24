//  https://leetcode.cn/problems/largest-number/

class Solution
{
public:
    string largestNumber(vector<int>& nums) // 将数组中的所有整数重新排列，拼接成最大的数字，并以字符串形式返回
    {
        vector<string> numstring; // 创建字符串数组，用于存储 nums 中每个整数转换后的字符串；注意不能写成 numstring()，否则会被解析为函数声明
        for (int e : nums) // 使用范围 for 循环，依次遍历 nums 中的每一个整数
            numstring.push_back(to_string(e)); // 使用 to_string 将整数转换为字符串，再通过 push_back 添加到 numstring 中
        sort(numstring.begin(), numstring.end(), [](const string& s1, const string& s2) { // 使用 sort 对字符串数组排序，并通过 Lambda 表达式自定义排序规则
            return s1 + s2 > s2 + s1; // 比较两种拼接顺序，若 s1+s2 大于 s2+s1，则将 s1 排在 s2 前面，从而使最终拼接结果最大
            }); // 排序结束，此时字符串数组中的元素已按照能够组成最大数字的顺序排列
        string ret; // 定义字符串 ret，用于保存所有数字按照排序结果拼接后形成的最大数字
        for (auto& e : numstring) // 使用范围 for 循环，依次遍历排序后的字符串数组；引用可以避免不必要的字符串复制
            ret += e; // 将当前字符串追加到 ret 的末尾，逐步拼接出最终结果
        if (numstring[0] == "0") // 如果排序后的第一个字符串是 "0"，说明数组中的所有数字都是 0（题目保证 nums 非空且元素非负）
            return "0"; // 直接返回 "0"，避免出现 "00"、"000" 等包含多余前导零的结果
        return ret; // 返回拼接完成的字符串，即能够组成的最大数字
    }
};