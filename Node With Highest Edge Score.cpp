class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        unordered_map<int, long long int> mp;
        long long int maxi = INT_MIN, res=0;
        for(int i=0; i<n; i++) {
            mp[edges[i]] += i;
        }
        for(auto it: mp) {
            if(maxi<it.second || (maxi == it.second && res > it.first)) {
                maxi = it.second;
                res = it.first;
            }
        }
        return res;
    }
};