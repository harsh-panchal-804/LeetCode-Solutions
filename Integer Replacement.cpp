class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<long long,int>> queue;
        queue.push({(long long )n,0});
        while(!queue.empty()){
            int s=queue.size();
            for(int i=0;i<s;i++){
                long long val=queue.front().first;
                int lvl=queue.front().second;
                queue.pop();
                if(val==1)return lvl;
                if(val%2==0)queue.push({val/2,lvl+1});
                else{
                    queue.push({val+1,lvl+1});
                    queue.push({val-1,lvl+1});
                }
            }
        }
        return -1;
        
    }
};