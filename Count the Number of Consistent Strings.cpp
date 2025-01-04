class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        unordered_set<char>st;
        int c = 0;
        for(auto ch: allowed)
        {
            st.insert(ch);
        }
        for(auto word: words)
        {
            bool flag = 1;
            for(auto ch: word)
            {
                if(st.find(ch)==st.end())
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                c++;
            }
        }
        return c;
    }
};