class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<vector<long long>> aa(2),bb(2);
        for(auto i : nums){
            aa[i%2].push_back(i);
        }
        for(auto i : target){
            bb[i%2].push_back(i);
        }
        sort(aa[0].begin(),aa[0].end());
        sort(aa[1].begin(),aa[1].end());
        sort(bb[0].begin(),bb[0].end());
        sort(bb[1].begin(),bb[1].end());
        long long ans=0;
        for(long long i=0;i<aa[0].size();i++){
            ans += abs(aa[0][i]-bb[0][i])/2;
        }
        for(long long i=0;i<aa[1].size();i++){
            ans += abs(aa[1][i]-bb[1][i])/2;
        }
        return ans/2;


    }
};