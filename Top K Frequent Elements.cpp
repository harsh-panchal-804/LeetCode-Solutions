class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int>&b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> map;
        for(auto i:nums){
            map[i]++;
        }
        vector<pair<int,int>> vec;
        for(auto i: map){
            vec.push_back(i);
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
        
    }
};