class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        unordered_map<int,vector<int>> map;
        for(int i=r-1;i>=0;i--){
            for(int j=0;j<c;j++){
                map[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        int di=0;
        while(map.contains(di)){
            if(di%2==1){
                reverse(map[di].begin(),map[di].end());
            }
            for(auto i : map[di]){
                ans.push_back(i);
            }
            di++;
        }
        return ans;
        
    }
};