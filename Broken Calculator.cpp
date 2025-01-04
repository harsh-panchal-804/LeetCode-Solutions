class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>target)return startValue-target;
        queue<pair<int,int>> queue;
        unordered_map<int,bool> map;
        queue.push({target,0});
        while(!queue.empty()){
            int s=queue.size();
            for(int i=0;i<s;i++){
                int val=queue.front().first;
                int lvl=queue.front().second;
                queue.pop();
                if(val==startValue)return lvl;
                if(val%2==0 && map[val/2]==false){
                    if(val/2<startValue){
                        return lvl +1+(startValue-val/2);

                    }
                    else{
                        map[val/2]=true;
                        queue.push({val/2,lvl+1});

                    }
                    
                }
                if(map[val+1]==false){
                    map[val+1]=true;
                    queue.push({val+1,lvl+1});
                }
            }
        }
        return -1;
        
    }
};