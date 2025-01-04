class Solution {
public:
    static bool cmp(string a,string b){
        return a+b>b+a;

    }
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(auto i:nums){
            vec.push_back(to_string(i));
        }
        sort(vec.begin(),vec.end(),cmp);
        string ans="";
        for(auto i: vec){
            ans+=i;
        }
        if(ans[0]=='0') return "0";
        else return ans;


        
    }
};