class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> vec(heights.begin(),heights.end());
        sort(vec.begin(),vec.end());
        int ans=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]!=heights[i])ans++;
        }
        return ans;
        
    }
};