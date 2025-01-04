class Solution {
public:
    int solve(string &s ,unordered_set<string>& set,int i){
        if(i>=s.size())return 0;
        int op1=-1e8;
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            // take or not
            if(set.count(temp)==0){
                set.insert(temp);
                op1=max(op1,1+solve(s,set,j+1));
                set.erase(temp);
            }
        }
        return op1;

    }
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return solve(s,set,0);
    }
};