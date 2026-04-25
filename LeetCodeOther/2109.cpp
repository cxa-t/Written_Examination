// https://leetcode.cn/problems/adding-spaces-to-a-string/

class Solution
{
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        int n = spaces.size();
        s.reserve(n + s.size());
        for (int i = 0; i < n; i++)
        {
            auto it = s.begin() + spaces[i] + i;
            s.insert(it, ' ');
        }
        //cout<<s<<endl;
        return s;
    }
};