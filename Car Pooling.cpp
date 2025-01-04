class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1e3+10,0);
        for(auto i : trips){
            int num=i[0];
            int from=i[1];
            int to=i[2];
            arr[from]+=num;
            arr[to]-=num;
        }
        vector<int> prefix(1e3+10);
        prefix[0]=arr[0];
        for(int i=1;i<prefix.size();i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        for(auto i : prefix){
            if(i>capacity)return false;
        }
        return true;

    }
};