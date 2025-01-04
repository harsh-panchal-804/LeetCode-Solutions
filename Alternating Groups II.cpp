class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        string s="";
        for(auto i : colors){
            s+=to_string(i);
        }
        int count=1;
        int ans=0;
        int n=colors.size();
        ///01010-01010
        for(int i=0;i<colors.size()+k-2;++i){
            if(s[i%n]!=s[(i+1)%n])++count;
            else count=1;
            if(count>=k)++ans;
        }
        return ans;
    }
};