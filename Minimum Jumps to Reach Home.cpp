class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forb(forbidden.begin(),forbidden.end());
        unordered_set<string> states;
        queue<tuple<int,int,int>>queue;
        queue.push({0,0,0});
        while(!queue.empty()){
            auto[curr,lvl,back]=queue.front();
            queue.pop();
            if(curr==x)return lvl;
            /////(forb.count(curr))continue;
            string ns=to_string(curr)+"-"+"F";
            if(curr+a<=6000&& !states.count(ns)&& !forb.count(curr+a)){
                states.insert(ns);
                queue.push({curr+a,lvl+1,0});
            }
            ns=to_string(curr)+"-"+"B";
            if(back==0 && curr-b>=0 &&!states.count(ns)&& !forb.count(curr-b)){
                queue.push({curr-b,lvl+1,1});
                states.insert(ns);
            }
        }
        return -1;
    }
};