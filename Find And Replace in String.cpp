class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = sources.size();
        unordered_map<int, int> matchedStringMap;
        for (int i = 0; i < n; ++i) {
            int pos = indices[i];
            bool isPresent = (s.substr(pos, sources[i].size()) == sources[i]);
            if (isPresent) {
                matchedStringMap[pos] = i;
            }
        }
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
           
            if (matchedStringMap.count(i) > 0) {
                res += targets[matchedStringMap[i]];
                i += sources[matchedStringMap[i]].size() - 1;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};