class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        unordered_map<int,int>map;
        sort(ans.begin(), ans.end());
        int rank = 1;
        for (int i : ans) {
            if (map.find(i) == map.end()) {
                map[i] = rank++; 
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = map[arr[i]];
        }
        return ans;
    }
};