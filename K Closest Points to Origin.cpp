class Solution {
public: 
    static bool cmp(pair<pair<int,int>,double>&a,pair<pair<int,int>,double>&b){
        return a.second<b.second;
    }


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<pair<int,int>,double>> vec;//x y value
        for(auto i : points){
            double x=pow(i[0],2)+pow(i[1],2);
            double dist=pow(x,0.5);
            vec.push_back({{i[0],i[1]},dist});
            cout<<dist<<endl;
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<vector<int>> ans;

        for(int i=0;i<k;i++){
            ans.push_back({vec[i].first.first,vec[i].first.second});
        }
        return ans;
        
    }
};