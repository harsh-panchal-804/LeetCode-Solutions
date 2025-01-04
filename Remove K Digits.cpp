class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>stack;
        if(num.size()==k)return "0";
        for(auto i : num){
            while(!stack.empty()&&k>0&&i<stack.back()){
                stack.pop_back();
                k--;
            }
            stack.push_back(i);
        }
        while(k>0){
            stack.pop_back();
            k--;
        }
        string ans="";
        int m=0;
        while(stack[m]=='0'&&m<stack.size()-1)m++;
        for(int i=m;i<stack.size();i++ ) ans+=stack[i];
        if(ans=="") return "0";
        return ans;


        
    }
};