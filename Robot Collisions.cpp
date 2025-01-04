class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n=positions.size();
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](int a ,int b){
            return positions[a]<positions[b];
        });
        stack<int> stack;
        for(auto curr: indices){
            if(directions[curr]=='R'){
                stack.push(curr);
            }
            else{
                while(!stack.empty() && health[curr]>0){
                    int top_index=stack.top();
                    int top_health=health[top_index];
                    stack.pop();
                    if(health[curr]>top_health){
                        health[top_index]=0;
                        health[curr]-=1; 
                    }
                    else if(top_health>health[curr]){
                        health[top_index]--;
                        stack.push(top_index);
                        health[curr]=0;
                    }
                    else{
                        health[top_index]=0;
                        health[curr]=0;
                    }
                }
            }
        }
        vector<int> ans;
        for(auto i : health){
            if(i>0){
                ans.push_back(i);
            }
        }
        return ans;


        
    }
};