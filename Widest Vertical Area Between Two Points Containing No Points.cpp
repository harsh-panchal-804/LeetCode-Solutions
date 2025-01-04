class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> vec;
        for(auto i:points){
            vec.push_back(i[0]);
        }
        sort(vec.begin(),vec.end());
        int mx=0;
        for(int i=1;i<vec.size();i++){
            mx=max(mx,vec[i]-vec[i-1]);
        }
        return mx;
        
    }
};