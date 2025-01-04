class Solution {
public:
    static bool cmp(vector<int> & a,vector<int>& b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort by finishin time
        sort(pairs.begin(),pairs.end(),cmp);
        int count=0;
        int prev=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(prev<pairs[i][0]){
                count++;
                prev=pairs[i][1];
            }
        }
        return ++count;
        
    }// 1 2 ,, 4 5 ,, 7 8
};