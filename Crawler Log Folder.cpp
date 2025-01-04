class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> stack;
   
        for(auto &i: logs){
            if(i=="../" && !stack.empty()){
                stack.pop_back();
            }
            else if(i!="./" && i!="../"){
              stack.push_back(i);
            }
            
        }
        return stack.size();
    }
};