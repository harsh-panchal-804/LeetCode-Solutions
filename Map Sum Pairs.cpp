class MapSum {
private:
    map<string,int> map;
    bool isPrefix(const string &key, const string &prefix)
{
    int keylen = key.length();
    int prefixlen = prefix.length();
    if(prefixlen > keylen) return false;
    for(int i = 0; i < prefixlen; i++)
    {
            if(prefix[i] != key[i])
                return false;
    }
    return true;
}
public:
    
    MapSum() {
        ///unordered_map<string,int> map;

    }
    
    void insert(string key, int val) {
        map[key]=val;
        
    }
    
    int sum(string prefix) {
        
        int res = 0;
        for(auto &entry : map)
        {
        string key = entry.first;
        if(isPrefix(key, prefix))
            res += entry.second;
            }
    return res;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */