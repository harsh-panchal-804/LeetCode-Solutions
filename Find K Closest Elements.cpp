class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> vec;///diff,no
        for(auto i : arr){
            vec.push_back({abs(i-x),i});
        }
        for(auto i :vec)cout<<i.first<<"->"<<i.second<<endl;
        sort(vec.begin(),vec.end());
        cout<<endl;
        for(auto i :vec)cout<<i.first<<"->"<<i.second<<endl;
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};