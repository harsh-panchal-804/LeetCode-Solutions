class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> vec(n);
        for(auto pair:roads){
            vec[pair[0]]++;
            vec[pair[1]]++;
        }
        vector<pair<int,int>> freq;
        for(int i=0;i<n;i++){
            freq.push_back({i,vec[i]});
        }
        sort(freq.begin(),freq.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+= (long long )(n-i)*freq[i].second;
        }
        return ans;


        
    }
};