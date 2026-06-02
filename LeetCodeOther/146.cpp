// https://leetcode.cn/problems/lru-cache/


//注释掉的那种方法本质是：
//先保存当前节点
//删除旧节点
//把保存的节点重新插入到链表头部
//更新哈希表位置
//
//而现在用的这一行更好：
//_list.splice(_list.begin(), _list, listit);
//它是直接移动链表节点到头部，不需要删除再新建节点，效率更高。
class LRUCache
{
public:
    // 构造函数，初始化缓存容量
    LRUCache(int capacity)
        : _capacity(capacity)
    { }
    // 根据 key 获取对应的 value
    int get(int key)
    {
        // 在哈希表中查找 key 是否存在
        auto hashit = _hashmap.find(key);
        // 如果 key 存在
        if (hashit != _hashmap.end())
        {
            // 拿到该 key 在链表中的位置
            auto listit = hashit->second;
            
            // 取出当前链表节点中的 key-value
            // pair<int, int> kv = *listit;
            // 删除当前链表中的旧节点
            // _list.erase(listit);
            // 将刚才保存的 key-value 插入到链表头部，表示最近使用
            // _list.push_front(kv);
            // 更新哈希表，让 key 指向新的链表头部位置
            // _hashmap[key] = _list.begin();
            // 返回当前 key 对应的 value
            // return kv.second;

            // 更优写法：直接把当前节点移动到链表头部，不需要删除再插入
            _list.splice(_list.begin(), _list, listit);
            // 返回当前节点中的 value
            return listit->second;
        }
        // 如果 key 不存在，返回 -1
        else return -1;
    }

    // 插入或更新 key-value
    void put(int key, int value)
    {
        // 先在哈希表中查找 key 是否已经存在
        auto hashit = _hashmap.find(key);
        // 如果 key 已经存在，说明是更新操作
        if (hashit != _hashmap.end())
        {
            // 拿到该 key 在链表中的位置
            auto listit = hashit->second;

            // 取出当前链表节点中的 key-value
            // pair<int, int> kv = *listit;
            // 修改当前 key 对应的 value
            // kv.second = value;
            // 删除链表中的旧节点
            // _list.erase(listit);
            // 将更新后的 key-value 插入到链表头部，表示最近使用
            // _list.push_front(kv);
            // 更新哈希表，让 key 指向新的链表头部位置
            // _hashmap[key] = _list.begin();

            // 更优写法：直接把当前节点移动到链表头部
            _list.splice(_list.begin(), _list, listit);
            // 更新链表头部节点的 value
            listit->second = value;
            // 更新哈希表中 key 对应的链表位置
            _hashmap[key] = _list.begin();
        }
        // 如果 key 不存在，说明是新增操作
        else
        {
            // 如果缓存已经满了，需要删除最久未使用的节点
            if (_hashmap.size() == _capacity)
            {
                // 删除哈希表中最久未使用节点对应的 key
                _hashmap.erase(_list.back().first);
                // 删除链表尾部节点，也就是最久未使用的节点
                _list.pop_back();
            }
            // 将新的 key-value 插入到链表头部，表示最近使用
            _list.push_front(make_pair(key, value));
            // 在哈希表中记录 key 对应的链表位置
            _hashmap[key] = _list.begin();
        }
    }
private:
    // 哈希表：key -> key 在链表中的位置
    unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
    // 双向链表：头部是最近使用，尾部是最久未使用
    list<pair<int, int>> _list;
    // LRU 缓存的最大容量
    size_t _capacity = 0;
};