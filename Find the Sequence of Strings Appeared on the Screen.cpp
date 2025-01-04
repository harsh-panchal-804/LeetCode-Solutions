class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string start="a";
        ans.push_back(start);
        for(int i=0;i<target.size();i++){
            while(start.back()!=target[i]){
                start.back()=start.back()=='z'?'a':start.back()+1;
                ans.push_back(start);
            }
            if(i<target.size()-1){
                start.push_back('a');
                ans.push_back(start);
            }
        }
        return ans;
    }
};