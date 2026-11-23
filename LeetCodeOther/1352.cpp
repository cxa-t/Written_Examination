//https://leetcode.cn/problems/product-of-the-last-k-numbers/?envType=daily-question&envId=2026-11-23

class ProductOfNumbers 
{
public:
    ProductOfNumbers() 
    {
        _st.push_back(1); // 初始化前缀积数组，第一个元素设为1，方便后续计算
    }
    void add(int num) 
    {
        if(num == 0)
        {
            _st.clear(); // 遇到0，清空之前的前缀积
            _st.push_back(1); // 重新初始化前缀积，表示从0之后重新计算
        }
        else
        {
            _st.push_back(_st.back() * num); // 将当前数字与之前的前缀积相乘，得到新的前缀积
        }
    }
    int getProduct(int k)
    {
        if(k >= _st.size()) return 0; // 最近k个数字中包含0，乘积为0
        return _st.back() / _st[_st.size() - 1 - k]; // 利用前缀积相除，得到最后k个数字的乘积
    }
private:
    vector<int> _st; // 存储连续非零数字的前缀积
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */