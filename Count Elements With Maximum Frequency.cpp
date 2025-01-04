class Solution {
public:
    static bool cmp(pair<int,int> &a ,pair<int,int>& b){
        return a.second>b.second;
    }
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]++;
        }
        vector<pair<int,int>> vec;
        for(auto i : map){
            vec.push_back(i);
        }
        sort(vec.begin(),vec.end(),cmp);
        int ans=0;
        int maxfreq=vec[0].second;
        for(auto i : vec){
            if(i.second==maxfreq){
                ans+=i.second;
            }
        }
        return ans;

        
    }
};