class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        for(int i=0;i<s.size();i++){
            string temp=s.substr(i,s.length()-i+1) + s.substr(0,i);
            ans=min(ans,temp);
        }
        return ans;
    }
};