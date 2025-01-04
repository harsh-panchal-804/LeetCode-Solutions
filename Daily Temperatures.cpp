class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> stack;
        int index=0;
        for(int i=0;i<temperatures.size();i++){
            while(!stack.empty() && temperatures[i]>temperatures[stack.top()]){
                int index=stack.top();
                stack.pop();
                ans[index]=i-index;  
            }
            stack.push(i);
            
        }
        return ans;
        
    }
};