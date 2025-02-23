class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow){
        vector<pair<int,int>> vec;
        for(int i=0;i<plant.size();i++){
            vec.push_back({grow[i],plant[i]});
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        for(auto [g,p]: vec){
            ans=max(ans,g)+p;
        }
        return ans;


        
    }
};