

class AllOne 
{
public:
    unordered_map<string, int> count;
    set<pair<int, string>> st;

    AllOne() { count.clear(); }
    void inc(string key) 
    {
        if (count[key])
            st.erase({count[key], key});

        count[key]++;
        st.insert({count[key], key});
    }
    void dec(string key) 
    {
        st.erase({count[key], key});
        count[key]--;
        if (count[key] == 0)
            count.erase(key);
        else
            st.insert({count[key], key});
    }

    string getMaxKey() 
    {
        if (!st.empty())
            return st.rbegin()->second;
        return "";
    }

    string getMinKey() 
    {
        if (!st.empty())
            return st.begin()->second;
        return "";
    }
};