class Solution {
public:
    int minOperations(int n) {
        queue<pair<int,int>> queue;
        queue.push({n,0});
        unordered_map<int,bool> map;
        while(!queue.empty()){
            int s=queue.size();
            while(s--){
                int val=queue.front().first;
                int lvl=queue.front().second;
                if(val==0)return lvl;
                queue.pop();
                if(val &1){
                    queue.push({val+1,lvl+1});
                    queue.push({val-1,lvl+1});
                }
                else{
                    int a=val&-val;
                    queue.push({val-a,lvl+1});
                    queue.push({val+a,lvl+1});
                }
            }
        }
        return 0;
        
    }
};