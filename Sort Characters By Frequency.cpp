class Solution {
public:
    bool static cmp(pair<char, int>& a, pair<char, int>& b) {
        { return a.second > b.second; }
    }
    string frequencySort(string s) {
        map<char, int> map;
        for (auto i : s) {
            map[i]++;
        }
        vector<pair<char,int>> vec;
        for(auto i: map){
            vec.push_back(i);
        }
       
        sort(vec.begin(), vec.end(), cmp);
        string ans="";
        for (auto i : vec) {
            for(int j=0;j<i.second;j++){
                ans+=i.first;
            }
        }
        return ans;
    }
};