class Solution {
public:
    int remove(string &s ,int score,string del){
        vector<char> stack;
        int ans=0;
        for(auto i : s){
            if(i==del[1]&&!stack.empty()&& stack.back()==del[0]){
                stack.pop_back();
                ans+=score;
            }
            else {
                stack.push_back(i);
            }
        }
        s="";
        for(auto i : stack){
            s.push_back(i);
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>y){
            ans+=remove(s,x,"ab");
            ans+=remove(s,y,"ba");
        }
        else{
            ans+=remove(s,y,"ba");
            ans+=remove(s,x,"ab");
        }
        return ans;
        
    }
};