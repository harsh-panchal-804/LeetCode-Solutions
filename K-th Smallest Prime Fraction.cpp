class Solution {
public:
    static bool cmp(pair<pair<int,int>, double>&a,pair<pair<int,int>, double>&b){
        return a.second<b.second;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<pair<int,int>, double>> vec;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double d=(double) arr[i]/arr[j];
                vec.push_back({{arr[i],arr[j]},d});
            }
        }
        sort(vec.begin(),vec.end(),cmp);
        return {vec[k-1].first.first,vec[k-1].first.second};

        
    }
};