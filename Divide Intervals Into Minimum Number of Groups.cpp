class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> arr(1e6+2,0);
        for(auto i : intervals){
            int u=i[0];
            int v=i[1];
            arr[u]++;
            arr[v+1]--;
        }
        vector<int> prefix(arr.size()+1);
        prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        return *max_element(prefix.begin(),prefix.end());
    }
};