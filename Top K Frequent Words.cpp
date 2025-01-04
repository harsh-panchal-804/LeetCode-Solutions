class Solution {
public:
    static bool cmp(pair<string,int>& a,pair<string,int>&b){
        if(a.second!=b.second)return a.second>b.second;
        else return a.first<b.first;

    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> map;
        for(auto i: words){
            map[i]++;
        }
        vector<pair<string,int>> vec;

        for(auto i: map){
            vec.push_back(i);
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
        
    }
};