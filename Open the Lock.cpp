class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> visited(10000,0);
        for(auto i : deadends){
            visited[stoi(i)]=1;
        }
        if(visited[0]==1)return -1;
        visited[0]=1;
        queue<pair<int,string>> queue;
        queue.push({0,"0000"});

        while(!queue.empty()){
            int turn=queue.front().first;
            string num=queue.front().second;
            queue.pop();
            if(num==target)return turn;
            for(int d=0;d<4;d++){
                
                for(int i=-1;i<=1;i+=2){
                    string temp=num;
                    char& digit=temp[d];
                    digit=(digit-'0'+i+10)%10+'0';
                    if(!visited[stoi(temp)]){
                        queue.push({turn+1,temp});
                        visited[stoi(temp)]=1;
                    }
                }
            }
        }
        return -1;
        
    }
};