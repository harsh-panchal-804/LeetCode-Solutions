class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       unordered_set<string>obstacle;
        for(auto it:obstacles){
            obstacle.insert(to_string(it[0])+"_"+to_string(it[1]));
        }
        pair<int,int>p={0,1};
        int x=0,y=0;
        int maxDistance=0;
        for(int i=0;i<commands.size();i++) {
            int command=commands[i];
            if(command==-1)
                p={p.second,-p.first};
            else if(command==-2)
                p={-p.second,p.first};
            else{
                for(int j=0;j<command;j++){
                    int newX=x+p.first;
                    int newY=y+p.second;
                    string s=to_string(newX)+"_"+to_string(newY);
                    if(obstacle.find(s)==obstacle.end()){
                        x=newX;
                        y=newY;
                        maxDistance=max(maxDistance,x*x+y*y);
                    }
                    else 
                        break;
                }
            }
        }
        return maxDistance;
    }
};